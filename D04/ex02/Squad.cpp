#include "Squad.h"


/*********************************************************************
* Constructor Default
*********************************************************************/
Squad::Squad(void)
{
	std::cout << "Squad constructed." << std::endl;
	this->_unit_count = 0;
	this->_unit_first = nullptr;
}
/*********************************************************************
* Destructor
*********************************************************************/
Squad::~Squad(void)
{
	std::cout << "Squad destructed." << std::endl;
	int				i = -1;
	
	while (++i < this->_unit_count)
	{
		delete *this->getUnit(i);
	}	
}
/*********************************************************************
* Constructor (Copy)
*********************************************************************/
Squad::Squad(Squad const & src)
{
	std::cout << "Squad constructed (Copy)." << std::endl;
	this->_unit_count = src.getCount();
	int				i = -1;
	while (++i < this->_unit_count)
	{
		this->push(src.clone(strc.getUnit(i)));
	}	
}
/*********************************************************************
* Comment
*********************************************************************/
int Squad::getCount(void) const
{
	return (this->_unit_count);
}
/*********************************************************************
* Comment
*********************************************************************/
ISpaceMarine	* Squad::getUnit(int index)
{
	if (index < 0 || index > this->_unit_count -1)
		return (nullptr);
	ISpaceMarine *tmp = this->_unit_first;
	int i = 0;
	while (i < index)
		tmp = tmp->_next;
	return (tmp);
}
/*********************************************************************
* Comment
*********************************************************************/
int Squad::push(ISpaceMarine *unit)
{
	if (!this->_unit_count)
		this->_unit_first = unit;
	else
	{
		ISpaceMarine *tmp = this->_unit_first;
		while (tmp)
			tmp = tmp->_next;
		tmp->_next = unit;
	}
}
