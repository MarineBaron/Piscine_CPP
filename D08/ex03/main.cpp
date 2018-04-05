/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 22:06:16 by mbaron            #+#    #+#             */
/*   Updated: 2018/04/05 07:57:38 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Instruction.hpp"
# include <iostream>
# include <vector>

int   main(void)
{
  str::string bf = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
  unsigned int  size = bf.size();
  std::vector<Instruction> queue(size);
  std::vector<char> memory(1024);
  for(std::vector<char>::iterator it = memory.begin(); it < memory.end(); it++)
    *it = 0;

  int i = 0;
  while (i < size)
  {
    if (bf[i] == '+')
      Instruction ins = new InstructionPlus<std::vector>(memory, memory.begin(), queue, queue.begin());
    else if (bf[i] == '-')
      Instruction ins = new InstructionMinus<std::vector>(memory, memory.begin(), queue, queue.begin());
    else if (bf[i] == '>')
      Instruction ins = new InstructionSup<std::vector>(memory, memory.begin(), queue, queue.begin());
    else if (bf[i] == '<')
      Instruction ins = new InstructionInf<std::vector>(memory, memory.begin(), queue, queue.begin());
    else if (bf[i] == '[')
      Instruction ins = new InstructionOpen<std::vector>(memory, memory.begin(), queue, queue.begin());
    else if (bf[i] == ']')
      Instruction ins = new InstructionClose<std::vector>(memory, memory.begin(), queue, queue.begin());
    else if (bf[i] == '.')
        Instruction ins = new InstructionDot<std::vector>(memory, memory.begin(), queue, queue.begin());
    i++;
  }


  return 0;
}