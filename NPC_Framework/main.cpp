#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstdio>
#include <conio.h>
#include <vector>
#include <fstream>

using namespace std;

//NSC
string name = "npc";
int guil_id =11;
string guild = "NONE";
int id = 000;
int voice = 0;
int flags = 0;
string npctype = "AMBIENT";

//Attribute
int strenght = 20;
int dexterity = 20;
int mana_max = 25;
int mana = 25;
int hitpoints_max = 50;
int hitpoints = 50;

//Kampf-Taktik
string tactic = "NORMAL";

//Equippte Waffen
string sword = "NULL";
string bow = "NULL";
string rune[8];
string wep_s[75];
string wep_id[75];

//Inventory
bool ambient =0;
string items[100];
int many = 0;

//Visuals
string sex = "MALE";
string face_m = "Pony";
string face_t = "Face_N_NormalBart05";
string body = "BodyTex_N";
string armor = "NULL";
string anim = "Normal";
int fat = 1;


//Talente
bool special = 0;
int basic = 30;
int bow_s = 0;
int oneh_s = 0;
int twoh_s = 0;
int cros_s = 0;
int mage = 0;
string spec_s = "NO";

//Routine
string routin[5][6];
int position;
string com[6];




void nsc() //Basic informations about NPC
{
    char nsc_m;
    for(int x=1; x<2;)
    {
    system("cls");
    cout << "[1]Name:  \t"      << name     << endl;
    cout << "[2]Guild: \t"      << guild    << endl;
    cout << "[3]ID:    \t"      << id       << endl;
    cout << "[4]Voice: \t"      << voice    << endl;
    cout << "[5]Flags: \t"      << flags    << endl;
    cout << "[6]NPC Type: \t"   << npctype  << endl;
    cout << "[7]Back"                       << endl;
    nsc_m=getch();

    switch(nsc_m)
    {
    case '1':
        cout << "Enter name for your character: ";
        cin >> name;
        break;
    case '2':

        cout << "[1]  Farmer"         << "\t\t" << "[2]  Bandit"      << endl;
        cout << "[3]  Dragon Hunter"  << "\t"   << "[4]  Dementor"    << endl;
        cout << "[5]  Fire Mag"       << "\t\t" << "[6]  Water Mag"   << endl;
        cout << "[7]  Militia"        << "\t\t" << "[8]  None"        << endl;
        cout << "[9]  Novice"         << "\t\t" << "[10] Paladin"     << endl;
        cout << "[11] Pirate"         << "\t\t" << "[12] Mercenary"   << endl;
        cout << "[13] Convict"        << "\t\t" << "[14] Citizen"     << endl;
        cout << "\t [15] Enter own guild id" << endl;
        cin >> guil_id;

            switch(guil_id)
            {
            case 1:
                guild="BAU";
                break;
            case 2:
                guild="BDT";
                break;
            case 3:
                guild="DJG";
                break;
            case 4:
                guild="DMT";
                break;
            case 5:
                guild="KDF";
                break;
            case 6:
                guild="KDW";
                break;
            case 7:
                guild="MIL";
                break;
            case 8:
                guild="NONE";
                break;
            case 9:
                guild="NOV";
                break;
            case 10:
                guild="PAL";
                break;
            case 11:
                guild="PIR";
                break;
            case 12:
                guild="SLD";
                break;
            case 13:
                guild="STRF";
                break;
            case 14:
                guild="VLK";
                break;
            case 15:
                cout << "Enter own ID: ";
                cin >> guild;
                break;
            default:
                cout << "You choose wrong option";
                Sleep(1000);
            }
        break;
    case '3':
        cout << "Enter unique ID for your character: ";
        cin >> id;
        break;
    case '4':
        cout << "Chose voice for ambient statements" << endl;
        cout << "1-14 Male, 17 - Female 15 - Like Hero: ";
        cin >> voice;
        break;
    case '5':
        cout << "Flag for immortality (0-Mortal 1-Immortal): ";
        cin >> flags;
        break;
    case '6':
        cout << "Friend -Friend, Ambient -Depends on the guild," << endl;
        cout << "Hostile -Enemy, Main -Hero" << endl << "Enter: ";
        cin >> npctype;
        break;
    case '7':
        x++;
        break;
    default:
        cout << "You choose wrong option";
        Sleep(1000);
    }
    }

}

void attribute() //Changes for attributes (Strength, dexterity, mana and hitpoints)
{

    char attr_m;
    for(int y=1; y<2;)
    {
    system("cls");
    cout << "[1]Strength = "        << strenght         << endl;
    cout << "[2]Dexterity = "       << dexterity        << endl;
    cout << "[3]Mana Max = "        << mana_max         << endl;
    cout << "[4]Mana = "            << mana             << endl;
    cout << "[5]Hitpoints Max = "   << hitpoints_max    << endl;
    cout << "[6]Hitpoints = "       << hitpoints        << endl;
    cout << "[7]Back"                                   << endl;
    attr_m=getch();

    switch(attr_m)
    {
    case '1':
        cout << "Strength: ";
        cin >> strenght;
        break;
    case '2':
        cout << "Dexterity: ";
        cin >> dexterity;
        break;
    case '3':
        cout << "Mana Max: ";
        cin >> mana_max;
        break;
    case '4':
        cout << "Mana: ";
        cin >> mana;
        break;
    case '5':
        cout << "Hitpoints Max: ";
        cin >> hitpoints_max;
        break;
    case '6':
        cout << "Hitpoints: ";
        cin >> hitpoints;
        break;
    case '7':
        y++;
        break;
    default:
        cout << "You choose wrong option";
        Sleep(1000);
    }
}
}

void equipment() //Adding equipment like swords, bows and runes
{
    char equip_m;
    int ru;
	int w_id = 0;

    for(int b=1; b<2;)
    {
		fstream wep;
		int wpnid = 75;

        system("cls");
        cout << "[1]White Weapon \t"        ;
        if(wpnid>=0&&wpnid<75) cout << wep_s[wpnid]     << endl;
        else cout << sword << endl;
        cout << "[2]Distance Weapon \t"     << bow      << endl;
        cout << "[3]Rune"                   << endl;
		cout << "[4]Weapons list"			<< endl;
        cout << "[5]Back"                   << endl;
        equip_m=getch();

        switch(equip_m)
        {
        case '1':
			char wpn;

			system("cls");
			cout << "[1]Enter ID"		<< endl;
			cout << "[2]List position"	<< endl;
			wpn = getch();
			if(wpn=='1')
			{
            cout << "Enter full id: ";
            cin >> sword;
            wpnid=75;
			}else if(wpn=='2')
			{
			cout << "Enter position on list (0-74): ";
			cin >> wpnid;
			sword = wep_id[wpnid];
			}
            break;
        case '2':
            cout << "Enter full id:";
            cin >> bow;
            break;
        case '3':
            cout << "How many runes you want to equip(1-8): ";
            cin >> ru;
            for(int r=0; r < ru; r++)
            {
              cout << "Enter id of " << r+1 << " rune: ";
              cin >> rune[r];
            }
            break;
		case '4':
		    
			wep.open("weapons.txt", ios::in);
			if(wep.good())
			{
				system("cls");

				while( !wep.eof() )
				{

				cout << "[" << w_id << "]  ";
				getline(wep, wep_id[w_id]);
				w_id++;
				cout << wep_id[w_id];
				getline(wep, wep_s[w_id]);
				cout << wep_s[w_id] << endl;
				}
				system("PAUSE");
			}
			else
			{
				system("cls");
				cout << "Error, can't open file";
				Sleep(1000);
			}
			break;
        case '5':
            b++;
            break;
        default:
            cout << "You choose wrong option";
            Sleep(1000);
        }

    }
}

void inventory() //Editing inventory for NPC
{
    char inv_m;
    char another;
    int ed = 1;
    for(int k=1; k<2;)
    {
        system("cls");
        cout << "[1]Random inventory(Gold, food, potions) ";
        if(ambient==1)   cout << "YES"   << endl;
        else			 cout << "NO"    << endl;
        cout << "[2]Add item to inventory \t" << many << "/100" << endl;
        cout << "[3]Edit added items" << endl;
        cout << "[4]Back" << endl;
        inv_m=getch();

        switch(inv_m)
        {
        case '1':
            cout << "Do you want random inventory? 1-Yes 0-No";
            cin >> ambient;
            break;
        case '2':
            for(int a=1;a<2;)
            {
            if(many <= 99)
            {
            cout << "Enter full ID for item: ";
            cin >> items[many];
            cout << "Do you want to add another one? y-Yes n-No ";
            another=getch();
            if(another== 'y')
            {
                system("cls");
                many++;
                cout << many << "/100" << endl;
            }
            else
            a++;
            }
            else
            {
                cout << "Ther is no more place to add item";
                a++;
                Sleep(2000);
            }

            }
            break;
        case '3':
            ed =1;
            for(int e=1; e<2;)
            {
                if(items[ed-1] != "NULL")
                {
                cout << ed << "\t" << items[ed-1] << endl;
                ed++;
                }
                else
                e++;
            }
            cout << "Position on list of item that you want edit: ";
            cin >> ed;
            cout << "Enter new id or DELETE(To delete object): ";
            cin >> items[ed];
            break;
        case '4':
            k++;
            break;
        default:
            cout << "You choose wrong option";
            Sleep(1000);


    }
    }
}

void visuals() //Changing look of NPC
{
    char vis_m;
    for(int v=1;v<2;)
    {
        system("cls");
        cout << "[1]Sex            \t"  << sex      << endl;
        cout << "[2]Face Model     \t"  << face_m   << endl;
        cout << "[3]Face Texture   \t"  << face_t   << endl;
        cout << "[4]Body Texture   \t"  << body     << endl;
        cout << "[5]Armor          \t"  << armor    << endl;
        cout << "[6]Fatness        \t"  << fat      << endl;
        cout << "[7]Walk Animation \t"  << anim     << endl;
        cout << "[8]Back"                           << endl;
        vis_m=getch();

        switch(vis_m)
        {
        case '1':
            cout << "MALE or FEMALE: ";
            cin >> sex;
            break;
        case '2':
            cout << "Babe1 (1-8), BabeHair, FatBald, Fighter," << endl;
            cout << "Psionic, Pony, Bald, Thief" << endl;
            cout << "Face model without HUM_HEAD_ : ";
            cin >> face_m;
            break;
        case '3':
            cout << "Full face texture name: ";
            cin >> face_t;
            break;
        case '4':
            cout << "BodyTex_N -Normal(White), BodyTex_B -Black," << endl;
            cout << "BodyTex_P -Tattoos, BodyTexBabe_N -White Woman," << endl;
            cout << "BodyTexBabe_B -Black Woman" << endl;
            cout << "Full body texture name: ";
            cin >> body;
            break;
        case '5':
            cout << "Full armor ID: ";
            cin >> armor;
            break;
        case '6':
            cout << "Set fatness (1-5 is optimal): ";
            cin >> fat;
            break;
        case '7':
            cout << "Tired, Militia, Mage, Arrogance, Relaxed, Normal" << endl;
            cout << "Set animation for walking: ";
            cin >> anim;
            break;
        case '8':
            v++;
            break;
        default:
            cout << "You choose wrong option";
            Sleep(1000);
        }
    }
}

void talente() //Adding talents ad abilities
{
    char tal_m;

    for(int t=1; t<2;)
    {
        if(special==1) spec_s="YES";
        else spec_s="NO";

        system("cls");
        cout << "[1]Special skills                   \t" << spec_s  << endl;
        cout << "[2]Basic fight skills level (1-100) \t" << basic   << endl;
        cout << "[3]Bow skill (Added to basic)       \t" << bow_s   << endl;
        cout << "[4]One handed sword                 \t" << oneh_s    << endl;
        cout << "[5]Two handed sword                 \t" << twoh_s    << endl;
        cout << "[6]Crossbow                         \t" << cros_s  << endl;
        cout << "[7]Magic circles (0-6)              \t" << mage    << endl;
        cout << "[8]Back" << endl;
        tal_m=getch();

        switch(tal_m)
        {
        case '1':
            cout << "Acrobatic, Sneaking, etc. 1-Yes 0-No: ";
            cin >> special;
            break;
        case '2':
            cout << "Minimal level of skill for all weapons: ";
            cin >> basic;
            break;
        case '3':
            cout << "Bow skill: ";
            cin >> bow_s;
            break;
        case '4':
            cout << "One handed sword skill: ";
            cin >> oneh_s;
            break;
        case '5':
            cout << "Two handed sword skill: ";
            cin >> twoh_s;
            break;
        case '6':
            cout << "Crossbow skill: ";
            cin >> cros_s;
            break;
        case '7':
            cout << "Magic circle: ";
            cin >> mage;
            if(mage>6||mage<0) mage=0;
            break;
        case '8':
            t++;
            break;
        default:
            cout << "You choose wrong option";
            Sleep(1000);
        }
    }
}

void routine() //Making daily routine for NPC
{
    for(int r=1; r<2;)
    {
        char rout_m;
        system("cls");
        cout << "[1]Change routine"    << endl;
        cout << "[2]Display routine"   << endl;
        cout << "[3]Back"              << endl;
        rout_m=getch();

        switch(rout_m)
        {
        case '1':
            for(int ch=1; ch<2;)
            {
                char ch_m;
                system("cls");
                cout << "[1]Add action" << endl;
                cout << "[2]Back"       << endl;
                ch_m=getch();

                switch(ch_m)
                {
                case '1':
                    cout << "Witch position, from 1 to 5, you want edit: ";
                    cin >> position;
                    if(position<6&&position>0)
                    {
                    for(int cr=0; cr<6;cr++)
                    {
                        cout << com[cr] << endl;
                        cin >> routin[position-1][cr];
                    }
                    }
                    else
                    {
                        cout << "Error";
                        Sleep(1000);
                    }
                    break;
                case '2':
                    ch++;
                    break;
                default:
                    cout << "You choose wrong option";
                    Sleep(1000);
                }com[0]="Action:";

            }
            break;
        case '2':
            for(int dis=0;dis<5;dis++)
            {
                cout << dis+1 << "   ";
                for(int dis_s=0;dis_s<6;dis_s++)
                {
                    cout << routin[dis][dis_s] << " ; ";
                }
                cout << endl;
            }
            system("PAUSE");
            break;
        case '3':
            r++;
            break;
        default:
            cout << "You choose wrong option";
            Sleep(1000);
            break;
        }
    }
}

void edit() //Menu for editing information about NPC
{
    for(int i=1; i<2;)
    {
        system("cls");
    char edit_m;
    cout << "[1]NSC"                << endl;
    cout << "[2]Attribute"          << endl;
    cout << "[3]Kampf-Taktik"       << endl;
    cout << "[4]Equippte Waffen"    << endl;
    cout << "[5]Inventory"          << endl;
    cout << "[6]Visuals"            << endl;
    cout << "[7]Talente"            << endl;
    cout << "[8]Routine"            << endl;
    cout << "[9]Back"               << endl;
    edit_m=getch();

    switch(edit_m)
    {
    case '1':
        nsc();
        break;
    case '2':
        attribute();
        break;
    case '3':
        cout << "Actual tactic: " << tactic << endl;
        cout << "Fight tactics: COWARD, NORMAL, STRONG, MASTER" << endl;
        cin >> tactic;
        break;
    case '4':
        equipment();
        break;
    case '5':
        inventory();
        break;
    case '6':
        visuals();
        break;
    case '7':
        talente();
        break;
    case '8':
        routine();
        break;
    case '9':
        i++;
        break;
    default:
        cout << "You choose wrong option";
        Sleep(1000);
    }
    }


}
void preview() //Preview for script
{
    system("cls");
    cout << "instance " << guild << "_" << id << "_" << name << "(Npc_Default)" << endl;
    cout << "{" << endl;
    cout << "// ------ NSC ------" << endl;
    cout << "name   \t= " << "\""   << name     << "\";" << endl;
    cout << "guild  \t= GIL_"       << guild    << ";"   << endl;
    cout << "id     \t= "           << id       << ";"   << endl;
    cout << "voice  \t= "           << voice    << ";"   << endl;
    cout << "flags  \t= "           << flags    << ";"   << endl;
    cout << "npctype\t= NPCTYPE_"   << npctype  << ";"   << endl;
    cout << endl; ///////////////////////////////////////////////
    cout << "// ------ Attribute ------" << endl;
    cout << "attribute[ATR_STRENGTH]     \t= " << strenght      << ";" << endl;
    cout << "attribute[ATR_DEXTERITY]    \t= " << dexterity     << ";" << endl;
    cout << "attribute[ATR_MANA_MAX]     \t= " << mana_max      << ";" << endl;
    cout << "attribute[ATR_MANA]         \t= " << mana          << ";" << endl;
    cout << "attribute[ATR_HITPOINTS_MAX]\t= " << hitpoints_max << ";" << endl;
    cout << "attribute[ATR_HITPOINTS]    \t= " << hitpoints     << ";" << endl;
    cout << endl; ///////////////////////////////////////////////
    cout << "// ------ Kampf-Taktik ------" << endl;
    cout << "fight_tactic\t= FAI_HUMAN_" << tactic << ";" << endl;
    cout << endl; ///////////////////////////////////////////////
    cout << "// ------ Equippte Waffen ------" << endl;
    if(sword!="NULL")
        cout << "EquipItem (self, " << sword << ");" << endl;
    if(bow!="NULL")
        cout << "EquipItem (self, " << bow << ");" << endl;
    for(int run=0; run<8; run++)
    {
    if(rune[run]!="NULL")
        cout << "EquipItem (self, " << rune[run] << ");" << endl;
    }
    cout << endl; ///////////////////////////////////////////////
    cout << "// ------ Inventory ------" << endl;
    if(ambient==1) cout << "B_CreateAmbientInv     (self);" << endl;
    for(int inv=0; inv<100; inv++)
    {
        if(items[inv]!="NULL"&&items[inv]!="DELETE")
        cout << "CreateInvItems (self, " << items[inv] << ", 10);" <<endl;
    }
    cout << endl; ///////////////////////////////////////////////
    cout << "// ------ visuals ------" << endl;
    cout << "B_SetNpcVisual         (self, " << sex << ", \"Hum_Head_" << face_m << ", " << face_t <<", " << body << ", ";
    if(armor!="NULL") cout << armor;
    cout << ");" << endl;
    cout << "Mdl_SetModelFatness    (self, " << fat << ");" << endl;
    cout << "Mdl_ApplyOverlayMds    (self, \"Humans_" << anim << ".mds\");" << endl;
    cout << endl; ///////////////////////////////////////////////
    cout << "// ------ NSC-relevante Talente vergeben ------" << endl;
    if(special==1) cout << "B_GiveNpcTalents (self);" << endl;
    cout << endl; ///////////////////////////////////////////////
    cout << "// ------ Kampf-Talente ------" << endl;
    cout << "B_SetFightSkills (self, " << basic << ");" << endl;
    cout << endl; ///////////////////////////////////////////////
    cout << "// guter Bogenkämpfer" << endl;
    cout << "B_AddFightSkill (self, NPC_TALENT_BOW, "       << bow_s  << ");" << endl;
    cout << "B_AddFightSkill (self, NPC_TALENT_1H, "        << oneh_s << ");" << endl;
	cout << "B_AddFightSkill (self, NPC_TALENT_2H, "        << twoh_s << ");" << endl;
    cout << "B_AddFightSkill (self, NPC_TALENT_CROSSBOW, "  << cros_s << ");" << endl;
	cout << "B_AddFightSkill (self, NPC_TALENT_MAGE, "      << mage   << ");" << endl;
    cout << endl; ///////////////////////////////////////////////
    cout << "// ------ TA anmelden ------" << endl;
    cout << "daily_routine \t= Rtn_Start_" << id << ";" << endl;
    cout << "};" << endl;
    cout << endl; ///////////////////////////////////////////////
    cout << "FUNC VOID Rtn_Start_" << id << "()" << endl;
    cout << "{" << endl;
    for(int pre_r=0; pre_r<5; pre_r++)
    {
    if(routin[pre_r][1]!="NULL")
    cout << "TA_"<<routin[pre_r][1]<<"\t("<<routin[pre_r][2]<<","<<routin[pre_r][3]<<","<<routin[pre_r][4]<<","<<routin[pre_r][5]<<",\""<<routin[pre_r][6]<<"\");"<<endl;
    }
    cout << "};";

    system("PAUSE");
}

void gener() //Generating script
{
    fstream plik;
    plik.open( "person.txt",ios::out);
    if( plik.good()==true )
    {
    plik << "instance " << guild << "_" << id << "_" << name << "(Npc_Default)" << endl;
    plik << "{" << endl;
    plik << "// ------ NSC ------" << endl;
    plik << "name   \t= \""         << name     << "\";" << endl;
    plik << "guild  \t= GIL_"       << guild    << ";"   << endl;
    plik << "id     \t= "           << id       << ";"   << endl;
    plik << "voice  \t= "           << voice    << ";"   << endl;
    plik << "flags  \t= "           << flags    << ";"   << endl;
    plik << "npctype\t= NPCTYPE_"   << npctype  << ";"   << endl;
    plik << endl; ///////////////////////////////////////////////
    plik << "// ------ Attribute ------" << endl;
    plik << "attribute[ATR_STRENGTH]     \t= " << strenght      << ";" << endl;
    plik << "attribute[ATR_DEXTERITY]    \t= " << dexterity     << ";" << endl;
    plik << "attribute[ATR_MANA_MAX]     \t= " << mana_max      << ";" << endl;
    plik << "attribute[ATR_MANA]         \t= " << mana          << ";" << endl;
    plik << "attribute[ATR_HITPOINTS_MAX]\t= " << hitpoints_max << ";" << endl;
    plik << "attribute[ATR_HITPOINTS]    \t= " << hitpoints     << ";" << endl;
    plik << endl; ///////////////////////////////////////////////
    plik << "// ------ Kampf-Taktik ------" << endl;
    plik << "fight_tactic\t= FAI_HUMAN_" << tactic << ";" << endl;
    plik << endl; ///////////////////////////////////////////////
    plik << "// ------ Equippte Waffen ------" << endl;
    if(sword!="NULL")
        plik << "EquipItem (self, " << sword << ");" << endl;
    if(bow!="NULL")
        plik << "EquipItem (self, " << bow << ");" << endl;
    for(int run=0; run<8; run++)
    {
    if(rune[run]!="NULL")
        plik << "EquipItem (self, " << rune[run] << ");" << endl;
    }
    plik << endl; ///////////////////////////////////////////////
    plik << "// ------ Inventory ------" << endl;
    if(ambient==1) plik << "B_CreateAmbientInv     (self);" << endl;
    for(int inv=0; inv<100; inv++)
    {
        if(items[inv]!="NULL"&&items[inv]!="DELETE")
        plik << "CreateInvItems (self, " << items[inv] << ", 10);" <<endl;
    }
    plik << endl; ///////////////////////////////////////////////
    plik << "// ------ visuals ------" << endl;
    plik << "B_SetNpcVisual         (self, " << sex << ", \"Hum_Head_" << face_m << ", " << face_t <<", " << body << ", ";
    if(armor!="NULL") plik << armor;
    plik << ");" << endl;
    plik << "Mdl_SetModelFatness    (self, " << fat << ");" << endl;
    plik << "Mdl_ApplyOverlayMds    (self, \"Humans_" << anim << ".mds\");" << endl;
    plik << endl; ///////////////////////////////////////////////
    plik << "// ------ NSC-relevante Talente vergeben ------" << endl;
    if(special==1) plik << "B_GiveNpcTalents (self);" << endl;
    plik << endl; ///////////////////////////////////////////////
    plik << "// ------ Kampf-Talente ------" << endl;
    plik << "B_SetFightSkills (self, " << basic << ");" << endl;
    plik << endl; ///////////////////////////////////////////////
    plik << "// guter Bogenkämpfer" << endl;
    plik << "B_AddFightSkill (self, NPC_TALENT_BOW, "       << bow_s  << ");" << endl;
    plik << "B_AddFightSkill (self, NPC_TALENT_1H, "        << oneh_s << ");" << endl;
	plik << "B_AddFightSkill (self, NPC_TALENT_2H, "        << twoh_s << ");" << endl;
    plik << "B_AddFightSkill (self, NPC_TALENT_CROSSBOW, "  << cros_s << ");" << endl;
	plik << "B_AddFightSkill (self, NPC_TALENT_MAGE, "      << mage   << ");" << endl;
    plik << endl; ///////////////////////////////////////////////
    plik << "// ------ TA anmelden ------" << endl;
    plik << "daily_routine \t= Rtn_Start_" << id << ";" << endl;
    plik << "};" << endl;
    plik << endl; ///////////////////////////////////////////////
    plik << "FUNC VOID Rtn_Start_" << id << "()" << endl;
    plik << "{" << endl;
    for(int pre_r=0; pre_r<5; pre_r++)
    {
    if(routin[pre_r][1]!="NULL")
    plik << "TA_"<<routin[pre_r][1]<<"\t("<<routin[pre_r][2]<<","<<routin[pre_r][3]<<","<<routin[pre_r][4]<<","<<routin[pre_r][5]<<",\""<<routin[pre_r][6]<<"\");"<<endl;
    }
    plik << "};";
    plik.flush();
    cout << "Your work has been saved!";
    Sleep(3000);
    } else
    {
    system("cls");
    cout << "Error: File not opened";
    Sleep(2000);
    }
    plik.close();
    plik.clear();

}

int main() //Main menu
{
    for(int ma=0;ma<101;ma++)
    {
        cout << "Loading: " << ma << "%";
        Sleep(50);
        system("cls");
    }
    com[0]="Action without TA_:";
    com[1]="StartHH:";
    com[2]="StartMM:";
    com[3]="StopHH:";
    com[4]="StopMM:";
    com[5]="Place:";
    for(int dis=0;dis<5;dis++)
    {
    for(int dis_s=0;dis_s<6;dis_s++)
    {
    routin[dis][dis_s]="NULL";
    }
    }

    while(true)
    {
    char main_m;

    system("cls");

    cout << "NPC Generator                v.1.0.1"  << endl;
    cout << "[1]Edit informations about character"  << endl;
    cout << "[2]Preview script"                     << endl;
    cout << "[3]Generate script"                    << endl;
    cout << "[4]Exit"                               << endl;
    main_m=getch();
	
	

    switch(main_m)
    {
    case '1':
        edit();
        break;
    case '2':
        preview();
        break;
    case '3':
        gener();
        break;
    case '4':
        system("cls");
        cout << "Made by Mateusz Tryl" << endl << "Relase V.1.0.1";
        Sleep(2000);
        exit(0);
        break;
    default:
        cout << "You choose wrong option";
        Sleep(1000);
    }
    }


    return 0;
}