#ifndef PROFILE_HPP
#define PROFILE_HPP
#pragma once

#include <chrono>
#include <string>
#include <QDebug>

class LogDuration {
public:
  explicit LogDuration(const QString& msg = "")
    : message(msg + ": ")
    , start(std::chrono::steady_clock::now())
  {
  }

  ~LogDuration() {
    auto finish = std::chrono::steady_clock::now();
    auto dur = finish - start;
    qDebug() << message
       << std::chrono::duration_cast<std::chrono::microseconds>(dur).count()
       << " mcr" << endl;
  }
private:
  QString message;
  std::chrono::steady_clock::time_point start;
};

#define UNIQ_ID_IMPL(lineno) _a_local_var_##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMPL(lineno)

#define LOG_DURATION(message) \
  LogDuration UNIQ_ID(__LINE__){message};
#endif // PROFILE_HPP
