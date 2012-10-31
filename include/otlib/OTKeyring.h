/*************************************************************
 *    
 *  OTKeyring.h
 *  
 *  Mac has Keychain, Windows has DPAPI, Linux has Gnome-
 *  Keyring, KWallet, etc. The purpose of this class is to
 *  provide a simple, unified, cross-platform interface to
 *  all of them.
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA256
 
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, and GUI 
 *    
 *    	 -- Anonymous Numbered Accounts.
 *    	 -- Untraceable Digital Cash.
 *    	 -- Triple-Signed Receipts.
 *    	 -- Cheques, Vouchers, Transfers, Inboxes.
 *    	 -- Basket Currencies, Markets, Payment Plans.
 *    	 -- Signed, XML, Ricardian-style Contracts.
 *    
 *  Copyright (C) 2010-2012 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *  
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki 
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *    
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- OTLib.........A class library.......LICENSE:...LAGPLv3 
 *   -- OT-API........A client API..........LICENSE:...LAGPLv3
 *   -- testwallet....Command-line client...LICENSE:...LAGPLv3
 *   -- OT-Server.....Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (livewire_3001@yahoo.com).
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *    
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT-API, then you
 *   don't have to open-source your code--only your changes to
 *   Open Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open Transactions terms remain respected, with regard to
 *   the Open Transactions code itself.
 *    
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/OTLib/Lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *   
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.
 -----BEGIN PGP SIGNATURE-----
 Version: GnuPG v1.4.11 (Darwin)
 
 iQIcBAEBCAAGBQJOjvvUAAoJEAMIAO35UbuOBlMP/1LX0xJ9CrTOe1G/mgc+VygT
 JPVZDAbQDL/lJXOZMbaPJ/GaLXyEnTViHp97ERrlVuBQz+9uonIKCmPqAGYGVBG1
 MGV2QcscXU2aOUT1VPf2OYEOIul0h8FX2lixfqouH9/OkVsGRLr79Zu8z3zdsO4R
 ktQtjZEU6lnL2t6cmp/cuXlQnbz1xvxd56xNDR11YP07Z4x+CuDB4EAK+P9TfCwn
 tqq5yJmxJM9HtMoi3cUU7kXodKm1n1YZt7O46DOxHqbXqErHChN1ekSK0fXad614
 Gmh+5JfvHjx5XoFWMxb46aAAcUiG8+QpFBcKtSYP2X96k1ylgxMCzrK60ec/MxKV
 BzvP00OJ6PzzrTlcUaCgJ8ZX+0scOMvW0XKioEorozKSWNFvT4Drc4Thhy8u9ET3
 ru1enNFrjdxKjw2+ZTQcKSZjSRx2kMQ2od/dkqUlhe/M1cHGhseH6ls7pItrkykE
 ufZ9GlZoxYE+FRatIBPneT9WwsvFFvH+i6cQ/MM9pbTr19g6VPzVZ4U9E65BbTDB
 czITynH+uMtJLbprtCdQlsI+vqTgYNoY8AUsmnr1qUkp020qGlvwfCJVrooisTmm
 yIh+Yp/KBzySU3inzclaAfv102/t5xi1l+GTyWHiwZxlyt5PBVglKWx/Ust9CIvN
 6h9BYZFTZrh/OwBXCdAv
 =MUfS
 -----END PGP SIGNATURE-----
 **************************************************************/

#ifndef __OTKEYRING_H__
#define __OTKEYRING_H__

// DLL Export for Win32

#undef EXPORT
#ifdef _WINDLL
  #define EXPORT __declspec(dllexport)
#else
  #define EXPORT
#endif

#include <string>

// It's better to turn-on one of these, by using the Makefile,
// instead of hardcoding it here, which is entirely unnecessary. 
//
// Nevertheless, I have added this comment anyway, in case that's
// what you want to do (for testing or whatever.)
//
//#define OT_KEYRING_WINDOWS 1
//#define OT_KEYRING_MAC     1
//#define OT_KEYRING_GNOME   1
//#define OT_KEYRING_KWALLET 1


class OTString;
class OTPassword;


class OTKeyring
{
    
public:
    
    // -------------------------------------------------------

    // NOTE: Normally the "username" in our context is related to the
    // master key. OTMasterKey will call OTKeyring::RetrieveSecret, and
    // will pass in probably a hash of the encrypted master key as the
    // "username", and will retrieve the cleartext master key as the
    // "password" (which it then uses as the password for all private
    // keys in the wallet.)
    // 
    // OT *already* caches its master key inside the OTMasterKey object
    // itself, for X minutes. So then, why have this additional step,
    // where we store it using whatever is the standard API for
    // "protected memory" on the user's computer? The answer is, so that
    // we can cache the password BETWEEN runs of the OT engine, and not
    // just DURING the CURRENT run. For example, only this sort of
    // caching makes it possible to set the user free from still having
    // to enter his password for every run of an OT script.
    //
    // I don't even know if I recommend using this OTKeyring, since I
    // don't necessarily trust the operating system's protected memory,
    // and since the password is vulnerable during the time it is cached
    // by the OS, since any other process ALSO running as the same user
    // is able to ask the OS what the cached value is.
    //
    // (So be careful what software you run on your computer...)
    // In fact, perhaps OT should ONLY run as a certain user, which is
    // not used for anything else. Have it be setuid. That way, even if 
    // a hacker can trick you into running his trojan as your own user,
    // he will be unable to query the OS for your master key, since your
    // user is not what was used to cache the PW in the first place (a 
    // special "OT user" being used instead.) And thus cannot be used to
    // retrieve it, either.
    //
EXPORT    static bool StoreSecret(    const OTString      & strUser, 
                                const OTPassword    & thePassword,
                                const std::string   & str_display);
    
EXPORT    static bool RetrieveSecret( const OTString      & strUser, 
                                      OTPassword    & thePassword,
                                const std::string   & str_display);
    
EXPORT    static bool DeleteSecret(   const OTString      & strUser,
                                const std::string   & str_display);
    
    // -------------------------------------------------------
#if defined(OT_KEYRING_WINDOWS) && defined(_WIN32)
EXPORT    static bool Windows_StoreSecret(    const OTString      & strUser, 
                                        const OTPassword    & thePassword,
                                        const std::string   & str_display);
    
EXPORT    static bool Windows_RetrieveSecret( const OTString      & strUser, 
                                              OTPassword    & thePassword,
                                        const std::string   & str_display);
    
EXPORT    static bool Windows_DeleteSecret(   const OTString      & strUser,
                                        const std::string   & str_display);
//#endif
    // -------------------------------------------------------
#elif defined(OT_KEYRING_MAC) && defined(__APPLE__)
    static bool Mac_StoreSecret(    const OTString      & strUser, 
                                    const OTPassword    & thePassword,
                                    const std::string   & str_display);
    
    static bool Mac_RetrieveSecret( const OTString      & strUser, 
                                         OTPassword     & thePassword,
                                    const std::string   & str_display);
    
    static bool Mac_DeleteSecret(   const OTString      & strUser,
                                    const std::string   & str_display);
//#endif
    // -------------------------------------------------------
#elif defined(OT_KEYRING_GNOME)
    static bool Gnome_StoreSecret(   const OTString     & strUser, 
                                     const OTPassword   & thePassword,
                                     const std::string  & str_display);
    
    static bool Gnome_RetrieveSecret(const OTString     & strUser, 
                                           OTPassword   & thePassword,
                                     const std::string  & str_display); // unused
    
    static bool Gnome_DeleteSecret(  const OTString     & strUser,
                                     const std::string  & str_display); // unused
//#endif
    // -------------------------------------------------------
#elif defined(OT_KEYRING_KWALLET)
    
    static KWallet::Wallet * m_wallet;
    static KApplication    * m_app;
    // -------------------------------------
    static bool KWallet_StoreSecret(   const OTString     & strUser, 
                                       const OTPassword   & thePassword,
                                       const std::string  & str_display);
    
    static bool KWallet_RetrieveSecret(const OTString     & strUser, 
                                             OTPassword   & thePassword,
                                       const std::string  & str_display);
    
    static bool KWallet_DeleteSecret(  const OTString     & strUser,
                                       const std::string  & str_display);
#endif
    // -------------------------------------------------------
};



















#endif // __OTKEYRING_H__






















/*
 
 
 Daughter of Babylon
 
 
Go down, sit in the dust, virgin daughter of Babylon;
  sit on the ground without a throne.
Oh beautiful Babylon, sit now in darkness, and silence.

Never again will you be known as the 'Lady of kingdoms.'
No more will you be called tender or delicate.

You said, "I am forever—the eternal queen!"
 But you did not consider these things,
 or reflect on what might happen.
 
Now then, listen, you lover of pleasure, 
 lounging in your security, and saying to yourself,
"I am, and there is none besides me."
They come from faraway lands, from the ends of the heavens—
  the LORD and the weapons of his wrath—to destroy the whole country.
 
Everyone shall turn to his own people,
  and everyone shall flee to his own land.
Like a hunted gazelle, like sheep without a shepherd,
 they will all return to their own people, 
 they will flee to their native land.

Behold, the least of the nations shall be a wilderness, 
  a dry land and a desert.
Your mother shall be deeply ashamed;
  she who bore you shall be ashamed.

This is the plan determined for the whole world;
this is the hand stretched out over all nations.

Oh, how the praise of the whole earth is seized!
 How Babylon has become desolate among the nations!
 
How the hammer of the whole earth has been cut apart and broken!
 How Babylon has become a desolation among the nations!
  For she has been proud against the LORD.

We would have healed Babylon, but she is not healed.
 Forsake her, and let us go everyone to his own country;
  For her judgment reaches to heaven 
    and is lifted up to the skies.

Oh you who dwell by many waters, abundant in treasures, your end has come.

Behold, I am against you, O destroying mountain, 
 who destroys all the earth,” says the LORD.
And I will stretch out My hand against you,
  roll you down from the rocks, 
   and make you a burnt mountain.
  
And though Babylon should mount up to heaven,
 and fortify her skies, destroyers will come to her from me,
   declares the LORD.
 
The broad walls of Babylon shall be utterly broken, 
 and her high gates shall be burned with fire.
 Because of the fire, the people and nations will labor in vain, 
   and they shall be weary.
 
Keep on, then, with your magic spells
 and with your many sorceries, 
  which you have labored at since childhood.
 
Let your astrologers come forward,
 those stargazers who make predictions month by month,
  let them save you from what is coming upon you.
 
Surely they are like stubble; the fire will burn them up.
  They cannot even save themselves from the power of the flame.
These are not coals for warmth, this is not a fire to sit by.
All of them go on in their error; there is not one that can save you.
  
Then the angel carried me away into a wilderness. 
  There I saw a woman sitting on a beast that resembled a
  leopard, with the feet of a bear and the mouth of a lion,
   with seven heads and ten horns.

 And the woman was arrayed in purple and scarlet,
  and decked with gold and precious stones and pearls,
   having a golden cup in her hand full of abominations
    and filthiness of her fornication.

And upon her forehead was a name written,
   Mystery, Babylon The Great,
   The Mother Of Harlots And Abominations Of The Earth.

The angel said, 
"The woman you saw is the great city that reigns over the kings of the earth.
 The seven heads are seven mountains on which the harlot sits.
 And they are also seven kings.
 Five have fallen, one is, and one is yet to come.
 The beast you saw was, and is not, and the people whose names are
 not written in the book of life shall wonder when they behold the beast
 that was, and is not, and yet is."

The angel said,
 "The ten horns will hate the whore. 
  They will bring her to ruin, and leave her naked.
  They will eat her flesh and burn her with fire.
  For God has put it into their hearts to do his will,
  and to give their power to the beast until God's words are fulfilled."

And the whole world wondered after the beast, saying, 
"Who is like the beast?
 Who can make war with the beast?"

I saw another angel come down from heaven, having great power,
 and the earth was lightened with his glory.
 
And he cried mightily with a strong voice, saying:
"Fallen! Fallen is Babylon the Great!
 She has become a home for demons,
  and a haunt for every evil spirit, 
  a haunt for every unclean and detestable bird.
 
For all the nations have drunk 
  the maddening wine of her adulteries. 
The kings of the earth committed adultery with her, 
  and the merchants of the earth grew rich 
   from her excessive luxuries.
 
In her heart she is proud, and she boasts, 
 "I sit as queen; I shall see no sorrow."

Therefore in one day her plagues will overtake her: 
 famine, mourning, and death. 
  She will be consumed by fire, 
   for mighty is the Lord God who judges her.
 
When the kings of the earth who committed adultery with her and shared her luxury
  see the smoke of her burning, they will weep and mourn over her.

Terrified at her torment, they will stand far off and cry:
"Woe! Woe, O great city, O Babylon, City of Power! 
 In one hour your doom has come!"

The merchants of the earth will weep and mourn over her,
   because no one buys their cargoes any more.
 
Cargoes of gold, silver, 
  precious stones and pearls,
  fine linen, and silk,
  and purple and scarlet cloth,
  every sort of citron wood,
And articles of every kind,
  made of costly wood, ivory,
  bronze, iron and marble.
Cargoes of cinnamon and spice, 
  of incense, myrrh and frankincense, 
  of wine and olive oil, 
  of fine flour and wheat,
  cattle and sheep,
  horses and carriages,
and bodies and souls of men.
 
The fruit that your soul longed for is gone from you.
  All your sumptuous things and shining splendor
   have perished from you,
  and you shall find them no more.

The merchants of these things, which were made rich by her,
  shall stand afar off, out of fear of her torment.

Weeping and wailing, they will say,
 "Woe! Woe, O great city, 
   clothed in fine linen, and decked in gold,
    precious stones and pearls!
"In one hour such great wealth has been brought to ruin!"
 
Every sea captain, and all who travel by ship, 
  the sailors, and all who earn their living from the sea, 
   will stand far off because of the fear of her torment.
When they see the smoke of her burning, they will exclaim:
 "Was there ever a city like this great city?"
 
They will throw dust on their heads, 
  and with weeping and mourning, cry out:
“Woe! Woe, O great city, 
 where all who had ships on the sea became rich through her wealth! 
In one hour she has been brought to ruin!”
 
Then a mighty angel picked up a boulder, 
 the size of a large millstone, 
  and threw it into the sea, and said:
 
  "With such violence,
    the great city of Babylon will be thrown down, 
     never to be found again.
 
   "The voice of musicians and harpists,
     flute players and trumpeters, 
     will never be heard in you again.
 
   "No workman of any trade
     will ever be found in you again.
 
   "The sound of a millstone 
     will never be heard in you again.
 
   "The light of a lamp 
     will never shine in you again.
 
   "The voice of bridegroom and bride 
     will never be heard in you again.
 
   "For your merchants were the world’s great men,
     and by your magic spell, all the nations were led astray."
 
 */






