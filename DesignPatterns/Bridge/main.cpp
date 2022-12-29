#include <iostream>
#include <string>

class DataReader{
public:
	virtual void read() = 0;
private:
};

class DataBaseReader : public DataReader{
public:
	void read() override {
		std::cout << "Info from data base" << std::endl;
	}
private:
};

class FileReader : public DataReader{
public:
	void read() override {
		std::cout << "Data from File" << std::endl;
	}
};

class Sender{
public:
	Sender(DataReader* dr) : reader(dr) {}
	void setDataReader(DataReader* dr) {
		reader = dr;
	}
	virtual void send() = 0;
protected:
	DataReader* reader;
};

class EmailSender : public Sender{
public:
	EmailSender(DataReader* dr) : Sender(dr) {}
	void send() override {
		reader->read();
		std::cout << "Sender by Email" << std::endl;
	}

};

class TelegramBotSender : public Sender{
public:
	TelegramBotSender(DataReader* dr) : Sender(dr) {}
	void send() override {
		reader->read();
		std::cout << "Sended by Telegram bot" << std::endl;
	}

};

int main(){

	Sender* sender = new EmailSender(new DataBaseReader());
	sender->send();

	sender->setDataReader(new FileReader());
	sender->send();

	sender= new TelegramBotSender(new DataBaseReader());
	sender->send();

	return 0;
}
