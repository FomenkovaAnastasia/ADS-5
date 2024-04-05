// Copyright 2021 NNTU-CS
#include <map>
#include "tstack.h"
#include <stack>

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
  std::string postfix;
  TStack<char, 100> stack;
  for (char c : inf) {
    if (isdigit(c)) {
      postfix = postfix + c + ' ';
    } else if (c == '(') {
      stack.push(c);
    } else if (precedence(c)) {
      while (!stack.isEmpty() && isOperator(stack.get()) >= isOperator(c)) {
        postfix = postfix + stack.get() + ' ';
        stack.pop();
      }
      stack.push(c);
    } else if (c == ')') {
      while (!stack.isEmpty() && stack.get() != '(') {
        postfix = postfix + stack.get() + ' ';
        stack.pop();
      }
      stack.pop();
    }
  }
}

int eval(std::string post) {
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
