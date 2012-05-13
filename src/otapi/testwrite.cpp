#include <iostream>
#include <fstream>
#include <string>
#include "BitcoinAcct.pb.h"
using namespace std;

// This function fills in a BitcoinAcct message based on user input.
void PromptForAddress(OT_GUI::BitcoinAcct* person) 
{
	cin.ignore(256, '\n');
	
	cout << "Enter Bitcoin Acct Name (blank for default): ";
	getline(cin, *person->mutable_bitcoin_name());
	
	cout << "Enter Bitcoin Acct ID (required): ";
	string email;
	getline(cin, email);
	if (!email.empty()) {
		person->set_bitcoin_id(email);
	}
	
	cout << "Enter GUI label (blank for none): ";
	string gui_label;
	getline(cin, gui_label);
	if (!gui_label.empty()) {
		person->set_gui_label(gui_label);
	}
}

// Main function:  Reads the entire address book from a file,
//   adds one person based on user input, then writes it back out to the same
//   file.
int main(int argc, char* argv[]) {
	// Verify that the version of the library that we linked against is
	// compatible with the version of the headers we compiled against.
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	
	if (argc != 2) {
		cerr << "Usage:  " << argv[0] << " WALLET_FILE" << endl;
		return -1;
	}
	
	OT_GUI::Wallet wallet;
	
	{
		// Read the existing wallet.
		fstream input(argv[1], ios::in | ios::binary);
		if (!input) {
			cout << argv[1] << ": File not found.  Creating a new file." << endl;
		} else if (!wallet.ParseFromIstream(&input)) {
			cerr << "Failed to parse GUI wallet." << endl;
			return -1;
		}
	}
	
	// Add a bitcoin acct.
	PromptForAddress(wallet.add_bitcoin_acct());
	
	{
		// Write the new wallet back to disk.
		fstream output(argv[1], ios::out | ios::trunc | ios::binary);
		if (!wallet.SerializeToOstream(&output)) {
			cerr << "Failed to write GUI wallet." << endl;
			return -1;
		}
	}
	
	// Optional:  Delete all global objects allocated by libprotobuf.
	google::protobuf::ShutdownProtobufLibrary();
	
	return 0;
}