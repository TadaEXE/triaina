#include <cstdint>
#include <functional>
#include <string>
#include <vector>

struct port;
struct node;

struct edge {
  uint64_t id;
  port* from;
  port* to;
};

enum port_type {
  in,
  out,
};

enum state {
  err,
  z,
  val,
};

struct port {
  uint64_t id;
  std::string label;
  port_type type;
  node* binding;
};

struct evaluator {
  uint64_t id;
  std::string label;
  std::function<void(std::vector<port*>, std::vector<port*>)> eval_func;
};

struct node {
  uint64_t id;
  std::vector<port*> ins;
  std::vector<port*> outs;
  evaluator* eval;
};
