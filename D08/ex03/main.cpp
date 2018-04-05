/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 22:06:16 by mbaron            #+#    #+#             */
/*   Updated: 2018/04/05 10:52:49 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Instruction.hpp"
# include <iostream>
# include <vector>

int   main(void)
{
  std::string bf = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
  unsigned int  size = bf.size();
  std::vector<Instruction> queue(size);
  std::vector<char> memory(1024);
  for(std::vector<char>::iterator it = memory.begin(); it < memory.end(); it++)
    *it = 0;

  unsigned int i = 0;
  while (i < size)
  {
    if (bf[i] == '+')
    {
      InstructionPlus inst(&memory, &queue, memory.begin(), queue.begin());
      queue.push_back(inst);
    }
    else if (bf[i] == '-')
    {
      InstructionMinus inst(&memory, &queue, memory.begin(), queue.begin());
      queue.push_back(inst);
    }
    else if (bf[i] == '>')
    {
      InstructionSup inst(&memory, &queue, memory.begin(), queue.begin());
      queue.push_back(inst);
    }
    else if (bf[i] == '<')
    {
      InstructionInf inst(&memory, &queue, memory.begin(), queue.begin());
      queue.push_back(inst);
    }
    else if (bf[i] == '[')
    {
      InstructionOpen inst(&memory, &queue, memory.begin(), queue.begin());
      queue.push_back(inst);
    }
    else if (bf[i] == ']')
    {
      InstructionClose inst(&memory, &queue, memory.begin(), queue.begin());
      queue.push_back(inst);
    }
    else if (bf[i] == '.')
    {
      InstructionDot inst(&memory, &queue, memory.begin(), queue.begin());
      queue.push_back(inst);
    }
    i++;
  }
  for(std::vector<Instruction>::iterator it = queue.begin(), end =  queue.end(); it != end; it++)
  {
    std::cout << it->getInstruction();
  }
  queue.begin()->execute();
  queue.clear();
  memory.clear();


  return 0;
}