<?php

require_once "otapi.php";

$wallet_path = "/Users/au/Projects/Open-Transactions/testwallet/data_folder";
$ot_init = otapi.OT_API_Init($wallet_path);
$switch_wallet = otapi.OT_API_SwitchWallet($wallet_path, "wallet.xml");
echo "OT_API_Init => " . var_dump($ot_init);
echo "OT_SwitchWallet => " . var_dump($switch_wallet);

?>
