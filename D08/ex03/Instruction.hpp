/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 22:00:41 by mbaron            #+#    #+#             */
/*   Updated: 2018/04/05 08:40:41 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_HPP
# define INSTRUCTION_HPP

# include <iostream>
# include <vector>

class Instruction
{
  public:
    typedef std::vector<char> Cmem;
    typedef std::vector<char>::iterator Imem;
    typedef std::vector<Instruction> Cins;
    typedef std::vector<Instruction>::iterator Iins;

    Instruction(Cmem & memory, Cins & queue, Imem * mit,  Iins * qit):
      _memory(memory), _queue(queue), _mit(mit), _qit(qit){};
    virtual ~Instruction(void){};
    Instruction(Instruction const & src): {*this = src;};
    Instruction &operator=(Instruction const & rhs){
      _instruction = rhs->getInstruction();
      _memory = rhs->getMemory();
      _mit = rhs->getMemoryIterator();
      _queue = rhs->getQueue();
      _qit = rhs->getQueueIterator();
      return *this;
    };

    char                getInstruction(void) const{return _instruction;};
    Cmem            & getMemory(void) const{return _memory;};
    Imem   * getMemoryIterator(void) const{return _mit;};
    Cins                & getQueue(void) const{return _queue;};
    Iins      * getQueueIterator(void) const{return _qit;};
    virtual void  execute(void) = 0;

  protected:
    char                          _instruction;
    Cmem                       & _memory;
    Cins                 & _queue;
    Imem             * _mit;
    Iins       * _qit;

  private:
    Instruction(void){};
};

class InstructionSup: public Instruction
{
  public:
    InstructionSup(Cmem & memory, CIns & queue, Imem * mit,  Iins * qit):
      Instruction(memory, queue, mit, qit), _instruction('>') {};
    ~InstructionSup(void){};
    InstructionSup(InstructionSup const & src){*this = src;};
    InstructionSup &operator=(InstructionSup const & rhs){Instruction::operator=(rhs); return *this;};
    void                execute(void)
    {
      _mit++;
    };
  private:
    InstructionSup(void){};
};
class InstructionInf: public Instruction
{
  public:
    InstructionInf(Cmem & memory, CIns & queue, Imem * mit,  Iins * qit):
      Instruction(memory, queue, mit, qit), _instruction('<') {};
    ~InstructionInf(void){};
    InstructionInf(InstructionInf const & src){*this = src;};
    InstructionInf &operator=(InstructionInf const & rhs){Instruction::operator=(rhs); return *this;};
    void                execute(void)
    {
      _mit--;
    };
  private:
    InstructionInf(void){};
};
class InstructionPlus: public Instruction
{
  public:
    InstructionPlus(Cmem & memory, CIns & queue, Imem * mit,  Iins * qit):
      Instruction(memory, queue, mit, qit), _instruction('+') {};
    ~InstructionPlus(void){};
    InstructionPlus(InstructionPlus const & src){*this = src;};
    InstructionPlus &operator=(InstructionPlus const & rhs){Instruction::operator=(rhs); return *this;};
    void                execute(void)
    {
      (*_mit)++;
    };
  private:
    InstructionPlus(void){};
};
class InstructionMinus: public Instruction
{
  public:
    InstructionMinus(Cmem & memory, CIns & queue, Imem * mit,  Iins * qit):
      Instruction(memory, queue, mit, qit), _instruction('-') {};
    ~InstructionMinus(void){};
    InstructionMinus(InstructionMinus const & src){*this = src;};
    InstructionMinus &operator=(InstructionMinus const & rhs){Instruction::operator=(rhs); return *this;};
    void                execute(void)
    {
      *(_mit)--;
    };
  private:
    InstructionMinus(void){};
};
class InstructionOpen: public Instruction
{
  public:
    InstructionOpen(Cmem & memory, CIns & queue, Imem * mit,  Iins * qit):
      Instruction(memory, queue, mit, qit), _instruction('[') {};
    ~InstructionOpen(void){};
    InstructionOpen(InstructionOpen const & src){*this = src;};
    InstructionOpen &operator=(InstructionOpen const & rhs){Instruction::operator=(rhs); return *this;};
    void                execute(void)
    {
      int   open = 1;
      int   close = 0;
      if (*_mit)
      {
        _qit++;
        while (open != close)
        {
          if (*_qit.getInstruction() == '[')
            open++;
          else if (*_qit.getInstruction() == ']')
            close++;
          _qit++;
        }
      }
    };
  private:
    InstructionOpen(void){};
};
class InstructionClose: public Instruction
{
  public:
    InstructionClose(Cmem & memory, CIns & queue, Imem * mit,  Iins * qit):
      Instruction(memory, queue, mit, qit), _instruction(']') {};
    ~InstructionClose(void){};
    InstructionClose(InstructionClose const & src){*this = src;};
    InstructionClose &operator=(InstructionClose const & rhs){Instruction::operator=(rhs); return *this;};
    void                execute(void)
    {
      int   open = 0;
      int   close = 1;
      if (*_memory)
      {
        _qit--;
        while (open != close)
        {
          if (*_qit.getInstruction() == '[')
            open++;
          else if (*_qit.getInstruction() == ']')
            close++;
          _qit--;
        }
      }
    };
  private:
    InstructionClose(void){};
};
class InstructionDot: public Instruction
{
  public:
    InstructionDot(Cmem & memory, CIns & queue, Imem * mit,  Iins * qit):
      Instruction(memory, queue, mit, qit), _instruction('.') {};
    ~InstructionDot(void){};
    InstructionDot(InstructionDot const & src){*this = src;};
    InstructionDot &operator=(InstructionDot const & rhs){Instruction::operator=(rhs); return *this;};
    void                execute(void)
    {
      std::cout << *_mit;
    };
  private:
    InstructionDot(void){};
};
#endif