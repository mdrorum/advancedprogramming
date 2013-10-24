#include<iostream>

// we define several namespaces
namespace espacio {
    int a;
    int b;
}


namespace space {
    int a;
}

namespace spazio {
    int a;
    int b;
}

namespace espace {
    int b;
}


// namespaces can have aliases
namespace frontier = space;
namespace frontier2 = space;

int main() {

    {
        using namespace spazio;

        espacio::a = 1;
        space::a = 2;
        a = 3;

        std::cout << "spazio::a = " << spazio::a << std::endl;
        //using namespace space; // this would cause an error: which namespace does a belong to?
        //a = 5;


    }


    {
        espacio::b = 3;
        using espace::b;

        //using espacio::b; // this can't be done
        using namespace espacio;

        b = 5;

        // explicit "using" with variables takes precedence
        std::cout << "espacio::b = " << espacio::b << std::endl;
        std::cout << "espace::b = " << espace::b << std::endl;
    }


    // namespaces follow blocks (except for global declaration)
    using namespace space;

    {
        using namespace spazio;
        //a = 20; ambiguous

    }
    a = 20; // unambiguous
    
    return 0;
}
