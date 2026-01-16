import java.io.*;
import java.net.*;
import java.util.*;

public class ChatServer {
    private static final int PORT = 12345;
    private static Map<String, Set<ClientHandler>> groups = new HashMap<>();

    public static void main(String[] args) {
        System.out.println("Chat server started...");
        try (ServerSocket serverSocket = new ServerSocket(PORT)) {
            while (true) {
                Socket clientSocket = serverSocket.accept();
                new Thread(new ClientHandler(clientSocket)).start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static class ClientHandler implements Runnable {
        private Socket socket;
        private PrintWriter out;
        private BufferedReader in;
        private String groupName;

        public ClientHandler(Socket socket) {
            this.socket = socket;
        }

        @Override
        public void run() {
            try {
                in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                out = new PrintWriter(socket.getOutputStream(), true);

                String input;
                while ((input = in.readLine()) != null) {
                    String[] command = input.split(" ", 2);
                    switch (command[0].toLowerCase()) {
                        case "addgroup":
                            addGroup(command[1]);
                            break;
                        case "joingroup":
                            joinGroup(command[1]);
                            break;
                        case "sendmessage":
                            sendMessage(command[1]);
                            break;
                        case "leavegroup":
                            leaveGroup();
                            break;
                        case "removegroup":
                            removeGroup(command[1]);
                            break;
                        case "sendfile":
                            sendFile(command[1]);
                            break;
                        default:
                            out.println("Unknown command: " + command[0]);
                    }
                }
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                try {
                    socket.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        private void addGroup(String name) {
            synchronized (groups) {
                if (!groups.containsKey(name)) {
                    groups.put(name, new HashSet<>());
                    out.println("Group " + name + " created.");
                } else {
                    out.println("Group " + name + " already exists.");
                }
            }
        }

        private void joinGroup(String name) {
            synchronized (groups) {
                if (groups.containsKey(name)) {
                    groupName = name;
                    groups.get(name).add(this);
                    out.println("Joined group " + name);
                } else {
                    out.println("Group " + name + " does not exist.");
                }
            }
        }

        private void sendMessage(String message) {
            if (groupName != null) {
                synchronized (groups) {
                    for (ClientHandler client : groups.get(groupName)) {
                        client.out.println("[" + groupName + "] " + message);
                    }
                }
            } else {
                out.println("You are not in a group.");
            }
        }

        private void leaveGroup() {
            if (groupName != null) {
                synchronized (groups) {
                    groups.get(groupName).remove(this);
                    out.println("Left group " + groupName);
                    groupName = null;
                }
            } else {
                out.println("You are not in a group.");
            }
        }

        private void removeGroup(String name) {
            synchronized (groups) {
                if (groups.containsKey(name)) {
                    groups.remove(name);
                    out.println("Group " + name + " removed.");
                } else {
                    out.println("Group " + name + " does not exist.");
                }
            }
        }

        private void sendFile(String filePath) {
            if (groupName != null) {
                try {
                    File file = new File(filePath);
                    String fileName = file.getName();
                    byte[] fileBytes = new byte[(int) file.length()];
                    FileInputStream fis = new FileInputStream(file);
                    BufferedInputStream bis = new BufferedInputStream(fis);
                    bis.read(fileBytes, 0, fileBytes.length);

                    synchronized (groups) {
                        for (ClientHandler client : groups.get(groupName)) {
                            if (client != this) {
                                client.sendFileInfo(fileName, fileBytes.length);
                                client.sendFileBytes(fileBytes);
                            }
                        }
                    }

                    bis.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } else {
                out.println("You are not in a group.");
            }
        }

        private void sendFileInfo(String fileName, int fileLength) {
            out.println("FILE " + fileName + " " + fileLength);
        }

        private void sendFileBytes(byte[] fileBytes) {
            try {
                OutputStream os = socket.getOutputStream();
                os.write(fileBytes);
                os.flush();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}

