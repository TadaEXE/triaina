#include "parser/driver.hpp"

#include "parser.tab.hpp"
#include "parser/ast/nodes.hpp"

namespace parser {

bool Driver::had_error() const { return !error_msg.empty(); }

void Driver::set_program(ast::NodeId<ast::Program> p) { ast.set_program(p); }

void Driver::set_filename(std::string&& fn) {
  filename = std::move(fn);
  file_id_for(filename);
}

size_t Driver::file_id_for(const std::string_view& fn) {
  auto it = file_ids.find(std::string(fn));
  if (it != file_ids.end()) return it->second;

  auto id = file_ids.size();
  file_ids.emplace(std::string(fn), id);
  return id;
}

ast::Span Driver::span_from(const parser::location& l) {
  const size_t fid = file_id_for(filename);
  return {.begin = {.file_id = fid,
                    .line = static_cast<uint32_t>(l.begin.line),
                    .col = static_cast<uint32_t>(l.begin.column)},
          .end = {.file_id = fid,
                  .line = static_cast<uint32_t>(l.end.line),
                  .col = static_cast<uint32_t>(l.end.column)}};
}

void Driver::on_error(int line, int col, const std::string& msg) {
  error_msg.push_back(std::to_string(line) + ":" + std::to_string(col) + ": " +
                      msg);
}

}  // namespace parser
