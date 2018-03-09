/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:37:55 by mbaron            #+#    #+#             */
/*   Updated: 2018/03/09 16:38:47 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"

int		main(void)
{
	std::cout << std::endl;
	std::cout << "-------------------------------" << std::endl;
	std::cout << "| Tests with statics objects. |" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	PlasmaRifle		plasma;
	PowerFist		power;
	Enemy			enemy(20, "Enemy");
	SuperMutant		super;
	RadScorpion		scorpion;
	Character		jo("Jo");
	
	enemy.takeDamage(2);
	enemy.takeDamage(-2);
	enemy.takeDamage(20);
	
	super.takeDamage(5);
	super.takeDamage(2);
	super.takeDamage(200);
	
	scorpion.takeDamage(5);
	scorpion.takeDamage(2);
	scorpion.takeDamage(100);
	
	std::cout << std::endl;
	std::cout << "|-------------------------------" << std::endl;
	std::cout << "| Tests with dynamics objects. |" << std::endl;
	std::cout << "|-------------------------------" << std::endl;
	
	Character*	zaz = new Character("zaz");
	std::cout << *zaz;

	
	Enemy*		sc = new RadScorpion();
	Enemy*		sp = new SuperMutant();
	AWeapon*	pr = new PlasmaRifle();
	AWeapon*	pf = new PowerFist();
	
	std::cout << std::endl;
	std::cout << "Zaz will fight a RadScorpion 4 times (RS should be killed)." << std::endl;
	std::cout << "-----------------------------------------------------------" << std::endl;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(sc);
	std::cout << *zaz;
	zaz->attack(sc);
	std::cout << *zaz;
	zaz->attack(sc);
	std::cout << *zaz;
	zaz->attack(sc);
	std::cout << *zaz;
	std::cout << "-------" << std::endl;
	std::cout << std::endl;
	std::cout << "Zaz will fight a SuperMutan 2 times (SM sould stay alive)." << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl;
	zaz->equip(pf);
	std::cout << *zaz;
	zaz->attack(sp);
	std::cout << *zaz;
	zaz->attack(sp);
	std::cout << *zaz;
	std::cout << "-------" << std::endl;
	std::cout << std::endl;
	std::cout << "Zaz will recover AP and fight a SuperMutant 2 times (SM should be killed)." << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	zaz->recoverAP();
	zaz->recoverAP();
	std::cout << *zaz;
	zaz->attack(sp);
	std::cout << *zaz;
	zaz->attack(sp);
	std::cout << *zaz;
	std::cout << "-------" << std::endl;
	std::cout << std::endl;
	std::cout << "Zaz quit his equipment." << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl;
	zaz->equip(0);
	std::cout << *zaz;
	std::cout << "-------" << std::endl;
	std::cout << std::endl;
	std::cout << "Armes are destroyed." << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl;
	delete pr;
	delete pf;
	std::cout << "-------" << std::endl;
	std::cout << std::endl;
	std::cout << "Zaz is destroyed." << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl;
	delete zaz;
	std::cout << "-------" << std::endl;
	std::cout << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << "| Delete statics objects. |" << std::endl;
	std::cout << "---------------------------" << std::endl;
	return 0;
}
