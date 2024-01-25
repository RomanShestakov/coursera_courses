#include<iostream>

struct File {
    int a_;
    File( int a ) : a_{ a } { std::cout << "File ctor" << std::endl; }
    virtual ~File() {}
};

struct InputFile : virtual public File {
    int b_;
    InputFile( int b) : File ( b * 2 ), b_{ b } {
        std::cout << "InputFile ctor" << std::endl;
    }
};


struct OutFile : virtual public File {
    int c_;
    OutFile( int c ) : File ( c * 3 ), c_{ c } {
        std::cout << "OutFile ctor" << std::endl;
    }
};

struct IOFile : public InputFile, public OutFile {
    int d_;
    IOFile( int d ) : File ( d ), InputFile( d * 5 ), OutFile( d * 7 ), d_{ d } {
        std::cout << "IOFile ctor" << std::endl;
    }
};


#if 0
struct IOFile2 : public IOFile {
    int e_;
    IOFile2( int e ) : IOFile ( e ), e_{ e } {
        std::cout << "IOFile2 ctor" << std::endl;
    }
};
#endif

int main() {

    IOFile f( 11 );
    std::cout << f.InputFile::a_ << std::endl;
    std::cout << f.OutFile::a_ << std::endl;
    std::cout << f.a_ << std::endl;

#if 0
    InputFile g( 11 );
    OutFile h( 11 );
    std::cout << g.a_ << std::endl;
    std::cout << h.a_ << std::endl;
    IOFile2 io2( 11 );
#endif

    return 0;
}
