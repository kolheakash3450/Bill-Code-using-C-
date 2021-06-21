//****************************************************************
// HEADER FILE USED IN PROJECT
//****************************************************************

#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>
#include<graphics.h>

    //***************************************************************
    // CLASS USED IN PROJECT
    //****************************************************************

    class product
    {
	int pno;
	char name[50], vname[30];
	float price, qty, tax, dis;
	public:
	    void create_product()
	    {
		cout << "\nPlease Enter The Product No. of The Product ";
		cin >> pno;
		cout << "\n\nPlease Enter The Name of The Product ";
		gets(name);
		cout<<endl<<"Enter Vendor Name : ";
		gets(vname);
		cout << "\nPlease Enter The Price of The Product ";
		cin >> price;
		cout << "\nPlease Enter The Discount (%) ";
		cin >> dis;
	    }

	void show_product()
	{
	    cout << "\nThe Product No. of The Product : " << pno;
	    cout << "\nThe Name of The Product : ";
	    puts(name);
	    cout<<endl<<"Name of the Vendor : ";
	    puts(vname);
	    cout << "\nThe Price of The Product : " << price;
	    cout << "\nDiscount : " << dis;
	}

	int retpno()
	{
	    return pno;
	}

	float retprice()
	{
	    return price;
	}

	char * retname()
	{
	    return name;
	}

	int retdis()
	{
	    return dis;
	}

    }; //class ends here

//***************************************************************
// global declaration for stream object, object
//****************************************************************

fstream fp;
product pr;
//***************************************************************
// function to write in file
//****************************************************************

void write_product()
{
    fp.open("Shop.dat", ios::out | ios::app);
    pr.create_product();
    fp.write((char * ) & pr, sizeof(product));
    fp.close();
    cout << "\n\nThe Product Has Been Created ";
    getch();
}
//***************************************************************
// function to read all records from file
//****************************************************************
void display_all()
{
    clrscr();
    cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
    fp.open("Shop.dat", ios:: in );
    while (fp.read((char * ) & pr, sizeof(product)))
    {
	pr.show_product();
	cout << "\n\n====================================\n";
	getch();
    }
    fp.close();
    getch();
}
//***************************************************************
// function to read specific record from file
//****************************************************************
void display_sp(int n)
{
    int flag = 0;
    fp.open("Agrobusiness.dat", ios:: in );
    while (fp.read((char * ) & pr, sizeof(product)))
    {
	if (pr.retpno() == n)
	{
	    clrscr();
	    pr.show_product();
	    flag = 1;
	}
    }
    fp.close();
    if (flag == 0)
	cout << "\n\nrecord not exist";
    getch();
}
//***************************************************************
// function to modify record of file
//****************************************************************
void modify_product()
{
    int no, found = 0;
    clrscr();
    cout << "\n\n\tTo Modify ";
    cout << "\n\n\tPlease Enter The Product No. of The Product";
    cin >> no;
    fp.open("Agrobusiness.dat", ios:: in | ios::out);
    while (fp.read((char * ) & pr, sizeof(product)) && found == 0)
    {
	if (pr.retpno() == no)
	{
	    pr.show_product();
	    cout << "\nPlease Enter The New Details of Product" << endl;
	    pr.create_product();
	    int pos = -1 * sizeof(pr);
	    fp.seekp(pos, ios::cur);
	    fp.write((char * ) & pr, sizeof(product));
	    cout << "\n\n\t Record Updated";
	    found = 1;
	}
    }
    fp.close();
    if (found == 0)
	cout << "\n\n Record Not Found ";
    getch();
}
//***************************************************************
// function to delete record of file
//****************************************************************
void delete_product()
{
    int no;
    clrscr();
    cout << "\n\n\n\tDelete Record";
    cout << "\n\nPlease Enter The product no. of The Product You Want To Delete";
    cin >> no;
    fp.open("Agrobusiness.dat", ios:: in | ios::out);
    fstream fp2;
    fp2.open("Temp.dat", ios::out);
    fp.seekg(0, ios::beg);
    while (fp.read((char * ) & pr, sizeof(product)))
    {
	if (pr.retpno() != no)
	{
	    fp2.write((char * ) & pr, sizeof(product));
	}
    }
    fp2.close();
    fp.close();
    remove("Shop.dat");
    rename("Temp.dat", "Shop.dat");
    cout << "\n\n\tRecord Deleted ..";
    getch();
}
//***************************************************************
// function to display all products price list
//****************************************************************

void menu()
{
    clrscr();
    fp.open("Shop.dat", ios:: in );
    if (!fp)
    {
	cout << "ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File";
	cout << "\n\n\n Program is closing ....";
	getch();
	exit(0);
    }

    cout << "\n\n\t\tProduct MENU\n\n";
    cout << "====================================================\n";
    cout << "P.NO.\t\tNAME\t\tPRICE\n";
    cout << "====================================================\n";

    while (fp.read((char * ) & pr, sizeof(product)))
    {
	cout << pr.retpno() << "\t\t" << pr.retname() << "\t\t" << pr.retprice() << endl;
    }
    fp.close();
}

//***************************************************************
// function to place order and generating bill for Products
//****************************************************************
void SetColor(int value)
    {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),value);
   }
void place_order()
{
    int order_arr[50], quan[50], c = 0;
    float amt, damt, total = 0;
    char ch = 'Y';
    menu();
    cout << "\n============================";
    cout << "\n PLACE YOUR ORDER";
    cout << "\n============================\n";
    do
    {
	cout << "\n\nEnter The Product No. Of The Product : ";
	cin >> order_arr[c];
	cout << "\nQuantity in number : ";
	cin >> quan[c];
	c++;
	cout << "\nDo You Want To Order Another Product ? (y/n)";
	cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << "\n\nThank You For Placing The Order";
    getch();
    clrscr();
    int i;
    char lucnr=201,llcnr=200,rlcnr=188,rucnr=187,vrt=186,hor=205;
    char hnhr=199,hntr=182;

   // system (color 0);



    cout<<endl<<"";
    cout<<endl<<"\t\t\t      Akash Agro-Mall\n";
    cout<<lucnr;
    for(i=0;i<70;i++)
    cout<<hor;
    cout<<rucnr;
    cout << "\n"<<vrt<<"\t\t\t\tINVOICE\t\t\t\t       "<<vrt<<"\n";
    cout<<hnhr;
    for(i=0;i<70;i++)
    cout<<hor;
    cout<<hntr;
    cout << "\n"<<vrt<<"Pr No.\tPr Name\tQuantity \tPrice \tAmount \tAmount after discount  "<<vrt<<endl;
    cout<<hnhr;
    for(i=0;i<70;i++)
    cout<<hor;
    cout<<hntr;
    for (int x = 0; x <= c; x++)
    {
	fp.open("Shop.dat", ios:: in );
	fp.read((char * ) & pr, sizeof(product));
	while (!fp.eof())
	{
	    if (pr.retpno() == order_arr[x])
	    {
		amt = pr.retprice() * quan[x];
		damt = amt - (amt * pr.retdis() / 100);
		cout << "\n"<<vrt<< order_arr[x] << "\t" << pr.retname() <<
		    "\t" << quan[x] << "\t\t" << pr.retprice() << "\t" << amt << "\t\t" << damt<<"\t       "<<vrt;
		total += damt;
	    }
	    fp.read((char * ) & pr, sizeof(product));
	}

	fp.close();
    }
    cout<<endl<<hnhr;
    for(i=0;i<70;i++)
    cout<<hor;
    cout<<hntr;
    cout << "\n"<<vrt<<"\t\t\t\t\tTOTAL = " << total<<"\t       "<<vrt;
    cout<<endl<<llcnr;
    for(i=0;i<70;i++)
    cout<<hor;
    cout<<rlcnr;
    getch();
}

//***************************************************************
// INTRODUCTION FUNCTION
//****************************************************************

void intro()
{
    clrscr();
    char lc;
    cout<<endl<<"";
    gotoxy(31, 11);
    cout << "AKASH AGRO-MALL";
    gotoxy(35, 14);
    cout << "BILLING";
    gotoxy(35, 17);
    cout << "PROJECT";
    cout << "\n\nMADE BY   : AKASH KOLHE";
    cout << "\n\nGUIDED BY : Prof. Alok Pawar";
    cout << "\n\nSwaraj College of Commerce and Computer Studies, Dhankawadi";
    getch();

}

//***************************************************************
// ADMINSTRATOR MENU FUNCTION
//****************************************************************
void admin_menu()
{
    clrscr();
    char ch2;
    cout << "\n\n\n\tADMIN MENU";
    cout << "\n\n\t1.CREATE PRODUCT";
    cout << "\n\n\t2.DISPLAY ALL PRODUCTS";
    cout << "\n\n\t3.QUERY ";
    cout << "\n\n\t4.MODIFY PRODUCT";
    cout << "\n\n\t5.DELETE PRODUCT";
    cout << "\n\n\t6.VIEW PRODUCT MENU";
    cout << "\n\n\t7.BACK TO MAIN MENU";
    cout << "\n\n\tPlease Enter Your Choice (1-7) ";
    ch2 = getche();
    switch (ch2)
    {
    case '1':
	clrscr();
	write_product();
	break;
    case '2':
	display_all();
	break;
    case '3':
	int num;
	clrscr();
	cout << "\n\n\tPlease Enter The Product No. ";
	cin >> num;
	display_sp(num);
	break;
    case '4':
	modify_product();
	break;
    case '5':
	delete_product();
	break;
    case '6':
	menu();
	getch();
    case '7':
	break;
    default:
	cout << "\a";
	admin_menu();
    }
}
//***************************************************************
// THE MAIN FUNCTION OF PROGRAM
//****************************************************************
void main()
{
    char ch;
    char lucnr=201,llcnr=200,ricnr=188,rucnr=187,vrt=186,hor=205;
    char hnhr=199,hntr=182;
    intro();
    do
    {
	clrscr();
	setcolor(2);
	cout << "\n\n\n\tMAIN MENU";
	cout << "\n\n\t01. CUSTOMER";
	cout << "\n\n\t02. ADMINISTRATOR";
	cout << "\n\n\t03. EXIT";
	cout << "\n\n\tPlease Select Your Option (1-3) ";
	ch = getche();
	switch (ch)
	{
	case '1':
	    clrscr();
	    place_order();
	    getch();
	    break;
	case '2':
	    admin_menu();
	    break;
	case '3':
	    exit(0);
	default:
	    cout << "\a";
	}
    } while (ch != '3');
}

//***************************************************************
// END OF PROJECT
//***************************************************************
