/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Instruction.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 22:00:41 by mbaron            #+#    #+#             */
/*   Updated: 2018/04/05 08:09:55 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_HPP
# define INSTRUCTION_HPP

template<typename T,
  typedef typename Cmem = T<char>,
  typedef typename Cins = T<Instruction>
  typedef typename Imem = Cmem::iterator,
  typedef typename Iins = Cins::iterator
  >
class Instruction
{
  public:
    Instruction(Cmem & memory, Cins & queue, Cmem * mit,  Cins * qit):
      _memory(memory), _queue(queue), _mit(mit), _qit(qit){};
    virtual ~Instruction(void){};
    Instruction(Instruction const & src){*this = src;};
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
    virtual void  execute(void){} = 0;
  protected:
    char                          _instruction;
    Cmem                       & _memory;
    Imem             * _mit;
    Cins                 & _queue;
    Iins       * _qit;

  private:
    Instruction(void){};
};

template<typename T>
class InstructionSup: public Instruction
{
  public:
    InstructionSup(T<char> & memory, T<Instruction> & queue, T<char>::iterator * mit,  T<Instruction>::iterator * qit):
      Instruction(memory, queue, mit, qit), _instruction = '>' {};
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
template<typename T>
class InstructionInf: public Instruction
{
  public:
    InstructionInf(T<char> & memory, T<Instruction> & queue, T<char>::iterator * mit,  T<Instruction>::iterator * qit):
      Instruction(memory, queue, mit, qit), _instruction = '<' {};
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
template<typename T>
class InstructionPlus: public Instruction
{
  public:
    InstructionPlus(T<char> & memory, T<Instruction> & queue, T<char>::iterator * mit,  T<Instruction>::iterator * qit):
      Instruction(memory, queue, mit, qit), _instruction = '+' {};
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
template<typename T>
class InstructionMinus: public Instruction
{
  public:
    InstructionMinus(T<char> & memory, T<Instruction> & queue, T<char>::iterator * mit,  T<Instruction>::iterator * qit):
      Instruction(memory, queue, mit, qit), _instruction = '-' {};
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
template<typename T>
class InstructionOpen: public Instruction
{
  public:
    InstructionOpen(T<char> & memory, T<Instruction> & queue, T<char>::iterator * mit,  T<Instruction>::iterator * qit):
      Instruction(memory, queue, mit, qit), _instruction = '[' {};
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
template<typename T>
class InstructionClose: public Instruction
{
  public:
    InstructionClose(T<char> & memory, T<Instruction> & queue, T<char>::iterator * mit,  T<Instruction>::iterator * qit):
      Instruction(memory, queue, mit, qit), _instruction = ']' {};
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
template<typename T>
class InstructionDot: public Instruction
{
  public:
    InstructionDot(C<char> & memory, T<Instruction> & queue, T<char>::iterator * mit,  T<Instruction>::iterator * qit):
      Instruction(memory, queue, mit, qit), _instruction = '.' {};
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