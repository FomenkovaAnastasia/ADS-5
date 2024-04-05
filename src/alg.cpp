// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
#include <iostream>

bool isOperator(char c) {
  return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
  if (c == '+' || c == '-') {
    return 1;
  } else if (c == '*' || c == '/') {
    return 2;
  }
  return 0;
}

std::string infx2pstfx(std::string inf) {
  TStack<char, 100> stack;
  std::string post;
  for (char c : inf) {
    if (std::isalnum(c)) {
      post += c;
    } else if (c == '(') {
      stack.push(c);
    } else if (c == ')') {
      while (!stack.isEmpty() && stack.top() != '(') {
        post += stack.pop();
      }
      stack.pop();
    } else {
      while (!stack.isEmpty() && precedence(c) <= precedence(stack.top())) {
        post += stack.pop();
      }
      stack.push(c);
    }
  }
  while (!stack.isEmpty()) {
    post += stack.pop();
  }
  return post;
  return std::string("");
}

int eval(std::string pref) {
  TStack<int, 100> stack;
  for (char c : post) {
    if (std::isdigit(c)) {
      stack.push(c - '0');
    } else if (isOperator(c)) {
      int operand2 = stack.pop();
      int operand1 = stack.pop();
      switch (c) {
        case '+':
          stack.push(operand1 + operand2);
          break;
        case '-':
          stack.push(operand1 - operand2);
          break;
        case '*':
          stack.push(operand1 * operand2);
          break;
        case '/':
          stack.push(operand1 / operand2);
          break;
      }
    }
  }
  return stack.pop();
  return 0;
}
