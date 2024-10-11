#include <iostream>
#include <thread>
#include <map>
#include <deque>
#include <vector>


// class Worker {

//  public:
//   Worker() {
//     _dq.clear();
//   }
//   void do_same_work(int channel, std::vector<int> &v) {
//     _dq[channel].insert(_dq[channel].end(), v.begin(), v.end());
//   }
//   std::vector<int> get_result(int channel) {
//     if (_dq[channel].empty() || (channel > _dq[channel].size())) {
//       return std::vector<int>();
//     } else {
//       std::vector<int> v = _dq[channel][0];
//       _dq[channel].pop_front();
//       return v;
//     }
//     return std::vector<int>();
//   }
//  private:
//   std::map<int, std::deque<std::vector<int>>> _dq;
// };

// void get_result(const Worker* worker, int channel) {
//   std::vector<int> v = worker->get_result(channel);
  
//   std::cout << "Channel " << channel << " : ";
//   for (int i = 0; i < v.size(); i++) {
//     std::cout << v[i] << " ";
//   }
//   std::cout << std::endl;
// }

void test_multithread(void) {
  // std::vector<std::thread> workers;
  // Worker worker;
  // for (int i = 0; i < 4; i++) {
  //   std::vector<int> v;
  //   for (int j = 0; j < 10; j++) {
  //     v.push_back(j);
  //   }
  //   workers.push_back(std::thread(&Worker::do_same_work, &worker, i, v));
  // }

  // std::vector<std::thread> result_workers;
  // for (int i = 0; i < 4; i++) {
  //   result_workers.push_back(std::thread(get_result, std::ref(worker), i));
  // }

  // for (int i = 0; i < 4; i++) {
  //   workers[i].join();
  // }
}