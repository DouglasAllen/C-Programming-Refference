/************************************************************************
 *
 * Purpose:
 * Author:  M J Leslie
 * Date:    26-Oct-98
 *
 ************************************************************************/


/* Known problems.

  Serious memory leaks
  not enough comments
  Has problems with vi swp files on Linux (so does normal grep).

*/


extern "C"
{
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
}

#include <iostream.h>

// DEBUG 1 == Debugging information is required.
// DEBUG 0 == Debugging info is suppresed.

#define DEBUG 0

class List
{
public:
    List()
    {
        Reset();
    }

    ~List()
    {
    }

    void Add(int Number)
    {
        Add(Number, ':');
    }

    void Add(int Number, char Prefix)
    {
        // Are we adding the first item in the list?

        if ( pFirstItem == 0 )
        {
            // Yes.

            pFirstItem = new IntList;
            pCurrentItem = pFirstItem;
        }
        else
        {
            // No. Add the number to the end of the list.

            pCurrentItem->pNext = new IntList;
            pCurrentItem        = pCurrentItem->pNext;
        }

        pCurrentItem->Item   = Number;
        pCurrentItem->Prefix = Prefix;
        pCurrentItem->pNext  = 0;
    }

    void PointToFirstEntry(void)
    {
        pCurrentItem = pFirstItem;
    }

    void Reset(void)
    {
        // This is going to cause seriuos memory leaks!

        pFirstItem   = 0;
        pCurrentItem = 0;
    }

    int GetCurrentEntry(void)
    {
    // Check we have a valid Item.

    if (pCurrentItem)
    {
            return (pCurrentItem->Item);
    }
    else
    {
        // No Item. This could happen when the list is empty.

        return (0);
    }
    }

    int GetNextEntry(void)
    {
        // Is there another entry in the list?

        if ( pCurrentItem->pNext != 0 )
        {
            // Yes. Give it to the caller.

            pCurrentItem = pCurrentItem->pNext;

            return (pCurrentItem->Item);
        }
        else
        {
            // No. 

            return (0);
        }
    }

    char GetCurrentPrefix(void)
    {
        // pCurrentItem = pCurrentItem->pNext;

        return (pCurrentItem->Prefix);
    }

    char GetNextPrefix(void)
    {
        pCurrentItem = pCurrentItem->pNext;

        return (pCurrentItem->Prefix);
    }

private:

    struct IntList
    {
        int         Item;
        char        Prefix;
        IntList    *pNext;
    };

    IntList *pFirstItem;
    IntList *pCurrentItem;
};

class grep
{
public:

    // enum { LL = 512 } LineLength ; 

    // .......................................................................

    grep()                    // Constructor.
    {

        OFF = 0;
        ON  = 1;

        LineNumbering     = ON;

        LinesBefore       = 2;
        LinesAfter        = 2;

        LinesInFile       = 0;

        pFileName         = 0;

        SearchString      = '\0';
        InsensitiveSearch = OFF;
    }

    // .......................................................................

    ~grep ()              // Distructor.
    {
        delete[] pFileName;
    }

    // .......................................................................

    void BuildMatrix(void)
    {
        int Line     = 0;
        int StartPos = 0;
        int EndPos   = 0;
        int NextPos  = 0;

        Debug("BuildMatrix");

        FoundLines.PointToFirstEntry();

        Line = FoundLines.GetCurrentEntry();
        Debug(Line);

        // Loop until we run out of line numbers.

        while ( Line > 0 )
        {
            // Find the first line to display.

            StartPos = Line - LinesBefore;

            if ( StartPos <= EndPos )
            {
                StartPos = EndPos + 1;
            }

            while ( StartPos < Line )
            {
                LineMatrix.Add(StartPos, ':');
                Debug(StartPos, 's');
                StartPos++;
            }

            LineMatrix.Add(Line, '*');
            Debug(Line, '*');

            EndPos = Line + LinesAfter;

            if ( EndPos > LinesInFile )
            {
                EndPos = LinesInFile;
            }

            NextPos = FoundLines.GetNextEntry();

            if ( NextPos > 0 && EndPos >= NextPos )
            {
                EndPos = NextPos - 1;
            }

            Line++;

            while ( Line <= EndPos )
            {
                LineMatrix.Add(Line, ':');
                Debug(Line, 'e');
                Line++;
            }

            Line = NextPos;
            Debug(Line);
        }
    }

    // .......................................................................

    void CaseInsensitive(void)
    {
        InsensitiveSearch = ON;
    }

    // .......................................................................

    void Diagnostic(void)
    {
        cout << endl << "Extra lines before the found line: " << LinesBefore << endl;

        if ( InsensitiveSearch )
        {
            cout << "Search is: Case Insensitive." << endl;
        }
        else
        {
            cout << "Search is: Case Sensitive." << endl;
        }
    }

    // .......................................................................

    int Exists(void)
    {
        // Have we got the file name?

        if ( pFileName == 0 )
        {
            // No.

            return (0);
        }
        else

        {
            // Yes. Check the file exists.

            struct stat stat_p;           /* 'stat_p' is a pointer to a structure
                                           * of type 'stat'.                      */

            /* Get stats for file and place them in
             * the structure.                       */


            if ( -1 ==  stat (pFileName, &stat_p) )
            {
                // File name not found.

                return (0);
            }

            if(!S_ISREG(stat_p.st_mode))
            {
                // This is not a regular file. It may be a directory.
                // Ignore it.

                return(0);
            }

            // File name is OK.

            return (1);
        }
    }

    // .......................................................................

    void Name(char *pFN)
    {
        Debug("Name", pFN);

        pFileName = new char[strlen(pFN)+1];
        strcpy(pFileName, pFN);
    }

    // .......................................................................

    void NoLineNumbers(void)
    {
        LineNumbering = OFF;
    }


    // .......................................................................

    void ProcessFile(void)
    {  
        int     Line;
        int     PreviousLine= 0;
        char    Prefix;
        int     CurrentLine = 0;
        char    Buffer[512];
        int     LineCount   = 0;

        FILE   *fp;

        Debug("ProcessFile");

        cout << endl << "Search String is: " << SearchString << endl;
        cout << "File Name is: "     << pFileName    << endl;

        fp = fopen (pFileName, "r");

        LineMatrix.PointToFirstEntry();

        Line   = LineMatrix.GetCurrentEntry();
        Prefix = LineMatrix.GetCurrentPrefix();

        while ( Line > 0 )
        {
            do
            {
                fgets(Buffer, 512, fp);
                LineCount ++;
            } while ( LineCount < Line );

            // Put in a seperator between blocks.

            if ( PreviousLine+1 < Line )
            {
                Seperator();
            }

            if ( LineNumbering )
            {
                cout << Line << Prefix << " " << Buffer;
            }
            else
            {
                cout << Prefix << " " << Buffer;

            }

            PreviousLine = Line;

            Line   = LineMatrix.GetNextEntry();
            Prefix = LineMatrix.GetCurrentPrefix();
        }

        Seperator();

        fclose(fp);
    }

    // .......................................................................

    void PutSearchString(char *String)
    {
        Debug("PutSearchString");
        Debug(String);

        SearchString = new char[strlen(String)+1];
        strcpy(SearchString, String);

        if ( InsensitiveSearch )
        {
            // Yes. Convert the buffer to uppercase.

            Uppercase(SearchString);
        }
    }

    // .......................................................................

    void Reset(void)
    {
        FoundLines.Reset();
        LineMatrix.Reset();
    }

    // .......................................................................

    int ScanFile(void)
    {
        FILE   *fp;
        char    Buffer[512];
        int     LineCounter = 0;
    int     Found       = 0;    // Number of lines that matched the search string.

        fp = fopen(pFileName, "r");

        Debug ("ScanFile");

        while ( !feof(fp) )
        {
            LineCounter++;

            fgets(Buffer, 512, fp);

        // Check the Buffer was big enough.

        if (strlen(Buffer) == 512 -1 )
        {
        cout << __FILE__ 
                     << ": Warning! Lines in " 
                     << pFileName 
                     << " exceed the max line length of " << 512 << endl;
            }

            // Are we doing a case insensitive search?

            if ( InsensitiveSearch )
            {
                // Yes. Convert the buffer to uppercase.

                Uppercase(Buffer);
            }

            if ( strstr(Buffer, SearchString) )
            {
                FoundLines.Add(LineCounter);
        Found++;
            }

        }
        fclose (fp);

        LinesInFile =  LineCounter;

    return(Found);
    }

    // .......................................................................

    void SetLines(int Lines)
    {
        SetLinesBefore(Lines);
        SetLinesAfter(Lines);
    }

    // .......................................................................

    void SetLinesBefore(int Lines)
    {
        LinesBefore = Lines;
    }

    // .......................................................................

    void SetLinesAfter(int Lines)
    {
        LinesAfter = Lines;
    }

private:

    // Debugging methods.

    void Debug(char *Message)
    {
        if ( DEBUG )
        {
            cout << "Debug: " << Message << endl;
        }
    }

    // .......................................................................
    void Debug(int Value)
    {
        if ( DEBUG )
        {
            cout << "Debug: " << Value << endl;
        }
    }

    // .......................................................................

    void Debug(int Value, char Char)
    {
        if ( DEBUG )
        {
            cout << "Debug: " << Char << " " << Value << endl;
        }
    }

    // .......................................................................

    void Debug(char * Str, int Value)
    {
        if ( DEBUG )
        {
            cout << "Debug: " << Str << " " << Value << endl;
        }
    }

    // .......................................................................

    void Debug(char * Str1, char * Str2)
    {
        if ( DEBUG )
        {
            cout << "Debug: " << Str1 << " " << Str2 << endl;
        }
    }

    // .......................................................................

    // Seperate blocks of data.

    void Seperator(void)
    {
        cout << "------"  << endl;
    }

    // .......................................................................


    void Uppercase(char *String)
    {
        int Offset = 0;

        while ( String[Offset] != (char)NULL )
        {
            String[Offset] = toupper(String[Offset]);
            Offset++;
        }
    }

    int     LineNumbering;        // ON = Line numbering required.
    int     LinesBefore;
    int     LinesAfter;

    int     LinesInFile;          // Number of lines in the file.
    int     InsensitiveSearch;    // ON = Case insensitive search required.

    char   *pFileName;            // File to be searched.
    char   *SearchString;

    List    FoundLines;           // List of lines that contain the search string.
    List    LineMatrix;           // List of lines that will be displayed.

    // Handy variables to set boolean variables.
    
    int     OFF;
    int     ON;

};  

//      Private functions.

void Debug(char *Message);

void Help(void);

void ProcessTheCommandLine(
                          int     argc,
                          char  **Argv);


//
//   Start point in the program.
//

main(
    int     Argc,
    char  **Argv)
{
    ProcessTheCommandLine(Argc, Argv);    
}

    // .......................................................................

void Help(void)
{
    cout << endl
         << " mgrep (Martins grep or Multi line grep) is an alternative to grep. " << endl
         << " The purpose is the same as grep in that it searches files " << endl
         << " looking for a supplied string. The difference is in the output, " << endl
         << " aswell as showing the line that contains the string, it also   " << endl
         << " shows the lines around the found line." << endl;

    cout << endl
         << " When reading from stdin, mgrep works a little differently to grep." << endl
         << " grep will scan the data on stdin looking for the search string." << endl
         << " mgrep assumes it is being passed file names, therefore it attempts " << endl
         << " to open the files and search the contents. " << endl;
    
    cout << endl
         << " Please note that mgrep is slower than grep, this is because it " << endl
         << " performs two passes over the files being searched. " << endl;

    cout << endl
         << "Syntax:" << endl << endl;

    // cout << " mgrep [ -d -h -l n -b n -a n -s] string [filenames]" << endl;
    cout << " mgrep [ -d -h -l n -b n -a n ] string [filenames]" << endl;
    cout << "" << endl;
    cout << " -h --------- Display this help." << endl;
    cout << " -d --------- Basic diagnostic information is printed." << endl;
    cout << " -i --------- Case insensitive search." << endl;
    cout << " -n --------- No line numbering required." << endl;
    cout << " -l n ------- Number of lines to show either side of the found line." << endl;
    cout << "              Default is 2." << endl;
    cout << " -b n ------- Number of lines to show before the found line." << endl;
    cout << "              Default is 2." << endl;
    cout << " -a n ------- Number of lines to show after the found line." << endl;
    cout << "              Default is 2." << endl;
    cout << " -s --------- Look for the list of files on STDIN." << endl;
    cout << " string ----- The string to search for." << endl;
    cout << " filenames -- List of files to search." << endl << endl;
}

    // .......................................................................

void Debug(char *Message)
{
    if ( DEBUG )
    {
        cout << "Debug: " << Message << endl;
    }
}

//
// Read the command line and act on its contents.
//

void ProcessTheCommandLine(
   int          Argc,
   char       **Argv)
{
    grep        File; 

    int         Flag               = 'x';
    int         LookAtStdin        = 0;
    int         FirstFile          = 1;
    int         DiagnosticRequired = 0;

    Debug("ProcessTheCommandLine");

    // Process the command line.

    for ( int Inc = 1; Inc < Argc; Inc++ )
    {
        // Have we got a flag?

        if ( *(Argv[Inc]) == '-' )
        {
            // Yes.

            Flag = *((Argv[Inc])+1);

            switch ( Flag )
            {
            case 'd':                     // Diagnostics requested
                DiagnosticRequired = 1;
                break;

            case 'h':                     // Help requested
                Help();
                exit(0);
                break;

            case 'i':                     // Case insensitive search
                File.CaseInsensitive();
                break;

            case 'l':                     // Number of lines to show either side of the found line.
                Inc++;
                File.SetLines(atoi(Argv[Inc]));
                break;

            case 'n':
                File.NoLineNumbers();
                break;

            case 'b':
                Inc++;
                File.SetLinesBefore(atoi(Argv[Inc]));
                break;

            case 'a':
                Inc++;
                File.SetLinesAfter(atoi(Argv[Inc]));
                break;

            case 's':
                LookAtStdin = 1;

            default:
                cout << Argv[Inc] << " is an invalid flag" << endl;
            }
        }
        else
        {
            // This is not a flag, it has to be 
            // the search string or a file name.

            if ( FirstFile )
            {
                // Assume the first word following 
                // the flags is the search string.

                File.PutSearchString(Argv[Inc]);

                if ( DiagnosticRequired )
                {
                    File.Diagnostic();
                }

                FirstFile = 0;
            }
            else
            {
                File.Name(Argv[Inc]);

                // ... If the file exists, 
                // ... find and display the lines that contain 
                // ... the search string.

                if ( !File.Exists() )
                {
                    // cout << "File " << Argv[Inc] << " not found. " << endl;
                }
                else
                {
            int Found = 0;

                    Debug("File Found");

                    Found = File.ScanFile();

            // Only proceed with this file if we found matching records.

            if  (Found > 0)
            {
                        File.BuildMatrix();
                        File.ProcessFile();
            }
                    File.Reset();
                }
            }
        }
    }

    // Should we scan stdin for file names?
    // This is a bodge because I cant figure out how to do a non blocking
    // read on sdtin.
    
    if (LookAtStdin)
    {
        // Yes.
        
        char FileName[256];

        // check we have a search string before looking in STDIN for filenames.

        if (FirstFile)
        {
            cout << __FILE__ << ": Search string not Supplied. " << endl;
            Help();
            return;
        }

        // Disable buffering on stdin. This mean that stdin can be
        // read without special cmd line flags and fgets does not 
        // lock up the program.

        char Buffer[BUFSIZ];

        // setvbuf(stdin, Buffer);

        // Now check STDIN for file names.

        while (fgets(FileName, 256, stdin))
        {
            FileName[strlen(FileName)-1] = '\0';
            // cout << "stdin loop" << FileName << endl;
            File.Name(FileName);

            // ... If the file exists,
            // ... find and display the lines that contain
            // ... the search string.

            if ( !File.Exists() )
            {
                // cout << "File " << FileName << " not found. " << endl;
            }
            else
            {
                int Found = 0;

                Debug("File Found");

                Found = File.ScanFile();

                // Only proceed with this file if we found matching records.

                if  (Found > 0)
                {
                    File.BuildMatrix();
                    File.ProcessFile();
                }
                File.Reset();
            }
        }
    }
}

