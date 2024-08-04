import java.io.*;
import java.net.*;

public class ChatClient {
    private static final String SERVER_ADDRESS = "localhost";
    private static final int SERVER_PORT = 12345;
    private static Socket socket;

    public static void main(String[] args) {
        try {
            socket = new Socket(SERVER_ADDRESS, SERVER_PORT);
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            BufferedReader stdIn = new BufferedReader(new InputStreamReader(System.in));

            new Thread(() -> {
                String serverMessage;
                try {
                    while ((serverMessage = in.readLine()) != null) {
                        if (serverMessage.startsWith("FILE ")) {
                            String[] fileInfo = serverMessage.split(" ");
                            String fileName = new File(fileInfo[1]).getName();
                            int fileLength = Integer.parseInt(fileInfo[2]);
                            receiveFile(fileName, fileLength);
                        } else {
                            System.out.println(serverMessage);
                        }
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }).start();

            String userInput;
            while ((userInput = stdIn.readLine()) != null) {
                if (userInput.toLowerCase().startsWith("sendfile ")) {
                    String filePath = userInput.substring(9);
                    sendFile(out, filePath);
                    sendFile(out, filePath);
                } else {
                    out.println(userInput);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void sendFile(PrintWriter out, String filePath) {
        out.println("SendFile " + filePath);
    }

    private static void receiveFile(String fileName, int fileLength) {
        try {
            byte[] buffer = new byte[fileLength];
            InputStream is = socket.getInputStream();
            try (FileOutputStream fos = new FileOutputStream(fileName)) {
                int bytesRead, totalRead = 0;

                while (totalRead < fileLength && (bytesRead = is.read(buffer, totalRead, fileLength - totalRead)) != -1) {
                    totalRead += bytesRead;
                    fos.write(buffer, totalRead - bytesRead, bytesRead);
                }

                System.out.println("File " + fileName + " received and saved.");
            }

            removeFirstLineFromFile(fileName);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void removeFirstLineFromFile(String fileName) {
        File inputFile = new File(fileName);
        File tempFile = new File("temp_" + fileName);

        try (BufferedReader reader = new BufferedReader(new FileReader(inputFile));
             PrintWriter writer = new PrintWriter(new FileWriter(tempFile))) {

            String currentLine;
            boolean isFirstLine = true;

            while ((currentLine = reader.readLine()) != null) {
                if (isFirstLine) {
                    isFirstLine = false;
                    continue;
                }
                writer.println(currentLine);
            }

            writer.flush();
            inputFile.delete();
            tempFile.renameTo(inputFile);

            System.out.println("First line removed from file " + fileName);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
