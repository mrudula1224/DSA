#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<optional>
using namespace std;

int countdigit(int n){
    int cnt = 0;
    while(n>0){
        int lastdigit = n%10;
        cnt = cnt+1;
        n = n/10;
    }
    return cnt;
}

int countdigitbylog(int n){
    int cnt = (int)(log10(n)) + 1;
    return cnt;
}

int reversenumber(int n){
    int reversenum = 0;
    while(n>0){
        int lastdigit = n%10;
        n= n/10;
        reversenum = (reversenum * 10)+ lastdigit;
    }
    return reversenum;
}

int pallindrome(int n){
    int reverse = 0;
    int dup = n;
    while(n>0){
        int lastdigit = n%10;
        if(reverse > INT_MAX/10) return 0;
        reverse = (reverse * 10)+lastdigit;
        n=n/10;
    }

    if(reverse == dup) cout<<"It is a palindrome"<<endl;
    else cout<<"It is not a palindrome"<<endl;

    return 0;
}

int armstrong(int n){
    int sum = 0;
    int temp = n;
    while(n>0){
        int lastdigit = n%10;
        n = n/10;
        sum = sum + (lastdigit*lastdigit*lastdigit);
    }
    if(sum == temp) cout<< "It is an Armstrong number"<<endl;
    else cout<<"It is not an Armstrong number"<<endl;
    return 0;
}

vector<int> factor(int n)
{
    vector<int> factorlist;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if(n%i == 0){
           factorlist.push_back(i);
           if (n/i != i){
            factorlist.push_back(n/i);
           }
        }
    }
    sort(factorlist.begin(), factorlist.end());
    return factorlist;
}

int gcd(int a , int b){
    while(a>0 && b>0){
        if(a>b){
            a = a%b;
        }
        else{
            b= b%a;
        }
    }
    return (a == 0) ? b : a;
}

int lcm(int a , int b){
    int hcf = gcd(a,b);
    int lcm1 = (a*b)/hcf;
    return lcm1;
}

int primenumber(int n){
    int cnt = 0;
    for (int i = 1; i*i <= n; i++){
        if(n%i == 0) {
            cnt++;
            if(n/i != i) cnt++;
        }
    }
    if(cnt == 2) cout<<"Yes, it is a prime number"<<endl;
    else cout<<"It is not a prime number"<<endl;
    return 0;
}

int main() {
    int choice;
    do {
        cout << "\n========= MENU =========\n";
        cout << "1. Count digits\n";
        cout << "2. Count digits (log method)\n";
        cout << "3. Reverse number\n";
        cout << "4. Check palindrome\n";
        cout << "5. Check Armstrong number\n";
        cout << "6. Find factors\n";
        cout << "7. GCD\n";
        cout << "8. LCM\n";
        cout << "9. Check prime number\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        int num, a, b;
        switch(choice) {
            case 1:
                cout << "Enter number: ";
                cin >> num;
                cout << "Count: " << countdigit(num) << endl;
                break;
            case 2:
                cout << "Enter number: ";
                cin >> num;
                if (num <= 0) {
                    cout << "Log method not valid for zero or negative numbers." << endl;
                } else {
                    cout << "Count (log method): " << countdigitbylog(num) << endl;
                }
                break;
            case 3:
                cout << "Enter number: ";
                cin >> num;
                cout << "Reversed: " << reversenumber(num) << endl;
                break;
            case 4:
                cout << "Enter number: ";
                cin >> num;
                pallindrome(num);
                break;
            case 5:
                cout << "Enter number: ";
                cin >> num;
                armstrong(num);
                break;
            case 6:
                cout << "Enter number: ";
                cin >> num;
                {
                    vector<int> factorlist = factor(num);
                    cout << "Factors: ";
                    for (int i = 0; i < factorlist.size(); ++i) {
                     cout << factorlist[i] << " ";
                    }
                    cout << endl;
                }
                break;
            case 7:
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "GCD: " << gcd(a, b) << endl;
                break;
            case 8:
                cout << "Enter two numbers: ";
                cin >> a >> b;
                cout << "LCM: " << lcm(a, b) << endl;
                break;
            case 9:
                cout << "Enter number: ";
                cin >> num;
                primenumber(num);
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while(choice != 0);

    return 0;
}
