#include <iostream>
using namespace  std;

class Singleton
{
public:
	  static Singleton* GetInstance()
	   {
	           if(instance_ == NULL)
			   {
			        instance_ = new Singleton();
			   }
			   return instance_;
	   }
	  /*  
	  //the second method(非线程安全)
	  static Singleton& GetInstance()
	   {
	          static Singleton  instance;
			  
			   return instance;
	   }
	   
	   Singleton& s1 = Singleton::GetInstance();
	   Singleton& s2 = Singleton::GetInstance();
	   */
	  ~Singleton()
	  {
	       cout<<" ~Singleton()..."<<endl;
    	}
	  class Garbo
	   {
	    public:
		      ~Garbo()
			  {
			           if(Singleton::instance_ != NULL)
				        {
				            delete instance_;
				        }
			   }
		};
private:
   	   Singleton& operator = (const Singleton& other);
	   Singleton(const Singleton & other);
	   Singleton()
	   {
	         cout<<"Singleton..."<<endl;
	    }
	    static Singleton* instance_;

		static Garbo garbo_;
};
Singleton * Singleton::instance_;
Singleton::Garbo Singleton::garbo_;

int main()
{
      Singleton *a1 = Singleton::GetInstance();
	  Singleton *a2 = Singleton::GetInstance();

	 // Singleton a3 (*a1); 拷贝构造函数

	
	  return 0;
}