/*
Three ways to create thread:

  1) Function Pointer
  2) function Objects
  3) Lambda function

New thread will start just after the creating of the new object and will execute the passed callback in paralled to thread that has started it.
any thread can wait for another to exit by calling join() function on that thread’s object.

*/

#include<iostream>
#include<thread>

//Creating a thread using function pointer
/*
void th_func(){
  for(int i=0;i<10;++i)
    std::cout<<"thread func executing"<<std::endl;
}

int main(){
  std::thread th_obj(th_func);
  for(int i=0;i<10;++i)
    std::cout<<"Display main thread"<<std::endl;
  th_obj.join();
  std::cout<<"End of main func"<<std::endl;
  return 0;
}*/

//Creating a thread using function object
/*
class Displaythread
{
public:
  void operator()()
  {
    for(int i=0;i<10;++i)
      std::cout<<"thread func executing"<<std::endl;
  }
};

int main(){
  std::thread th_obj((Displaythread()));
  for(int i=0;i<10;++i)
    std::cout<<"Display main thread"<<std::endl;
  std::cout<<"Waiting for thread to complete"<<std::endl;
  th_obj.join();
  std::cout<<"End of main func"<<std::endl;
  return 0;
}*/

//creating using lambda function
/*int main()
{
  int x = 9;
  std::thread th_obj([]{
    for(int i=0;i<10;++i)
      std::cout<<"thread func executing"<<std::endl;
  });
  for(int i=0;i<10;++i)
    std::cout<<"Display main thread"<<std::endl;
  th_obj.join();
  std::cout<<"End of main func"<<std::endl;
  return 0;
}*/

void th_func(){
  std::cout<<"Inside thread:: ID = "<<std::this_thread::get_id()<<std::endl;
}
int main(){
  std::thread th_obj1(th_func);
  std::thread th_obj2(th_func);
  if(th_obj1.get_id() != th_obj2.get_id())
    std::cout<<"Both threads have different IDS "<<std::endl;
  std::cout<<"From main thread ::ID of thread 1"<<th_obj1.get_id()<<std::endl;
  std::cout<<"From main thread ::ID of thread 2"<<th_obj2.get_id()<<std::endl;
  th_obj1.join();
  th_obj2.join();
  return 0;
}
