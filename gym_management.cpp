#include <iostream>
#include <vector>

class Member 
{
    private:
        std::string name ;
        int age;
        bool attendance;
    
    public:
        Member (std::string name, int age)   // constructor 可以直接改 private 的東西
        {
            this -> name = name;
            this -> age = age;
            this -> attendance = false;
        }
        std::string getName()
        {
            return name;
        }
        int getAge()
        {
            return age;
        }
        bool getAttendance()
        {
            return attendance;
        }
        void setAttendance(bool attendance)
        {
            this->attendance = attendance ;
        }

    
};

class Gym
{
    private:
        std::vector<Member> memberList;
    public:
        void addMember(std::string name, int age)
        {
            Member member(name, age);
            memberList.push_back(member);
            std::cout<<"Member Added"<<'\n'<<'\n';

        }
        void markAttendance(std::string name)
        {
            for(int i = 0; i < memberList.size(); i++)
            {
                if(name == memberList[i].getName())     // 可以用其他 class 中 public 的函式
                {
                    memberList[i].setAttendance(true);
                    std::cout<<"Attendance marked for member: "<< name <<std::endl<< std::endl;
                }
            }
        }
        void listAllMember()
        {
            for(int i = 0; i < memberList.size(); i++)
            {
                std::cout<<" Member"<<i<<":"<< memberList[i].getName()<<", "<<memberList[i].getAge() <<"y"<< std::endl<< std::endl;
            }
        }
        void fees()  
        {
            int totalFees = 0;
            for(int i = 0; i < memberList.size(); i++)
            {
                if(memberList[i].getAttendance())
                {
                    int memberFees = (memberList[i].getAge() > 20)? 200 : 100;
                    totalFees += memberFees;
                }
            }
            std::cout<<"Total Fees: "<<totalFees<<std::endl<<std::endl;
        }

};
int main()
{
    Gym gym;    // 如果放在 while，會導致每次重新宣告而更新 memberList
    
    while(true)
    {   
        int choice;
        std::cout<<"***** Gym Management *****"<<std::endl;
        std::cout<< "1. Add Member" << std::endl;
        std::cout<< "2. Mark Attendance" << std::endl;
        std::cout<< "3. Total Fees" << std::endl;
        std::cout<< "4. List All Members" << std::endl;
        std::cout<< "0. Exit" << std::endl;
        std::cout<< "Enter choice:";
        std::cin>>choice;
        
        if(choice == 1)
        {
            std::string currentMemberName;
            int currentMemberAge;
            std::cout<<"Please Enter Member's Name: ";
            std::cin>>currentMemberName;
            std::cout<<"Please Enter Member's Age: ";
            std::cin>>currentMemberAge;
            gym.addMember(currentMemberName, currentMemberAge);
        }
        else if(choice == 2)
        {
            
            std::string currentMemberName;
            std::cout<<"Please Enter Member's Name for Marked: ";
            std::cin>>currentMemberName;
            gym.markAttendance(currentMemberName);

        }
        else if (choice == 3)
        {
            gym.fees();
        }
        else if(choice == 4)
        {
            gym.listAllMember();
        }
        else if (choice == 0)
        {
            exit(0);
        }
        else
        {
            
            std::cout<<"Invalid Input, Please Enter Again!"<<std::endl<<std::endl;
        }
        
    }


}