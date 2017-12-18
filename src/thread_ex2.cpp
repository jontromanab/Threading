/*
Joining and Detaching threads
Once a thread is started then another thread can wait for this new thread to finish. For this another need to call join() function on the std::thread object i.e.

std::thread th(funcPtr);
th.join();

Suppose Main Thread has to start 10 Worker Threads and after starting all these threads, main function will wait for them to finish.
 After joining all the threads main function will continue,
*/

#include<iostream>
#include<thread>
#include<algorithm>

/*
class WorkerThread
{
public:
  void operator()()
  {
    std::cout<<"Worker Thread"<<std::this_thread::get_id()<<" is Executing"<<std::endl;
  }
};

int main(){
  std::vector<std::thread> th_list;
  for(int i=0;i<10;i++)
  {
    th_list.push_back(std::thread(WorkerThread()));
  }

  //Now wait for all the worker thread to fjinis. Call join() on each
  std::cout<<"Wait for all worker th to finish"<<std::endl;
  std::for_each(th_list.begin(), th_list.end(), std::mem_fn(&std::thread::join));
  std::cout<<"Exiting for main thread"<<std::endl;
  return 0;
}*/

//We shoudl not forget to call either join() or detach() in case of exceptions. To prevent this, we shoudl use,
//RAII( Resource Acquisition is Initialization)

class ThreadRAII
{
  std::thread& m_thread;
public:
  ThreadRAII(std::thread& th_obj) : m_thread(th_obj){}
  ~ThreadRAII(){
    if(m_thread.joinable())
      m_thread.detach();
  }
};

void th_func()
{
  for(int i=0;i<10;i++)
    std::cout<<"Thread_function executing"<<std::endl;
}

int main(){
  std::thread th_obj(th_func);
  ThreadRAII wrappedObj(th_obj);
  return 0;
}

