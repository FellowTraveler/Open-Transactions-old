#include <iostream>
#include <fstream>
#include <string>
#include "BitcoinAcct.pb.h"
using namespace std;

// Iterates though all people in the Wallet and prints info about them.
void ListBitcoinAccts(const OT_GUI::Wallet& wallet) 
{
  for (int i = 0; i < wallet.bitcoin_acct_size(); i++) 
  {
    const OT_GUI::BitcoinAcct& bitcoin_acct = wallet.bitcoin_acct(i);

    cout << "BitcoinAcct ID: " << bitcoin_acct.bitcoin_id() << endl;
	      
	  if (bitcoin_acct.has_bitcoin_name()) 
	  {
		  cout << "  Name: " << bitcoin_acct.bitcoin_name() << endl;
	  }
	  
	  if (bitcoin_acct.has_gui_label()) 
	  {
		  cout << "  GUI Label: " << bitcoin_acct.gui_label() << endl;
	  }
  }
}

// Main function:  Reads the entire address book from a file and prints all
//   the information inside.
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
    if (!wallet.ParseFromIstream(&input)) {
      cerr << "Failed to parse wallet." << endl;
      return -1;
    }
  }

  ListBitcoinAccts(wallet);

  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}
