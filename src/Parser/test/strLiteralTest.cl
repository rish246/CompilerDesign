(* This is a test for string Literals *)

class Main {
    my_string : String;
    x_ : Int <- 0; --single length variable names are not getting noticed -- Fix the lexer for this

    
    main() : Int {

        x_ = x_ + 1;

        -- not_x_;


    };

};
--Lookup is not working because x_ is not being fetched from the string Table and new Entries are being created every time
--Check the working of the parser
--I think the parser is not working correctly
(*Why did the core dumped in the end*)