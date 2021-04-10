#include <iostream>
#include <cassert>



float Calc(float a, char zn , float b)
{
    float res = 0;

     switch(zn)
    {
        case '+': res = a + b; break;
        case '-': res = a - b; break;
        case '*': res = a * b; break;
        case '/':
        {
            if (b == 0) {
                std::cout<< "Division by 0! Re-enter exp "<< std::endl;
                std::cin >> a >> zn >> b;
                
                
                return Calc(a,zn,b);
                break;
            }
            res = a / b;
             break;
        } 
        default:
        {
                std::cout<< "Wrong sign of operation! Re-enter exp "<< std::endl;
               std::cin >> a >> zn >> b;
                return Calc(a,zn,b);
                break;
        }
        
    }
    return res;
}

void CalcTests()
{
    assert(Calc(5,'*',4) == 20);
    assert(Calc(-5,'*',4) == -20);
    assert(Calc(-5,'*',-4) == 20);
    assert(Calc(5,'+',4) == 9);
    assert(Calc(5,'-',4) == 1);
    assert(Calc(10,'/',2) == 5);
    std::cout << "Tests Passed" << std::endl;
}

int main()
{
   
    float a = 0, b = 0, result = 0; 
    char znak;

    std::cout << "Enter exp: " << std::endl;
    std::cin >> a >> znak >> b;
    CalcTests();
    result = Calc(a, znak, b);
    
    std::cout << "Result: " << result  << std::endl;
    return 0;
}
