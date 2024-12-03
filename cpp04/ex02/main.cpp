/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkhai-ki <kkhai-ki@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:03:34 by kkhai-ki          #+#    #+#             */
/*   Updated: 2024/12/03 13:21:09 by kkhai-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#define ANIMAL_ARRAY_SIZE 10

int	main(void)
{
	{
		std::cout << "---Animal Array Test---" << std::endl;
		AAnimal	*animalArray[ANIMAL_ARRAY_SIZE + 1];
		animalArray[ANIMAL_ARRAY_SIZE] = NULL;

		std::cout << "---Adding Cats into the array---" << std::endl;
		for (int i = 0; i < ANIMAL_ARRAY_SIZE / 2; i++)
			animalArray[i] = new Cat();
		std::cout << std::endl;

		std::cout << "---Adding Dogs into the array---" << std::endl;
		for (int i = ANIMAL_ARRAY_SIZE / 2; i < ANIMAL_ARRAY_SIZE; i++)
			animalArray[i] = new Dog();
		std::cout << std::endl;

		std::cout << "---*Animal Noises*---" << std::endl;
		for (int i = 0; i < ANIMAL_ARRAY_SIZE; i++)
			animalArray[i]->makeSound();
		std::cout << std::endl;

		std::cout << "---Destroying Animals---" << std::endl;
		for (int i = 0; i < ANIMAL_ARRAY_SIZE; i++)
			delete (animalArray[i]);
		std::cout << std::endl;
	}
	{
		std::cout << "---Cat Brain Test---" << std::endl;
		Cat	*cat = new Cat();
		cat->getBrain()->setIdea("Amogus");
		std::cout << "cat's idea[0]: " << cat->getBrain()->getIdea(0) << std::endl;
		cat->getBrain()->setIdea("Fish");
		std::cout << "cat's idea[1]: " << cat->getBrain()->getIdea(1) << std::endl;
		Cat	*copyCat = new Cat(*cat);
		delete (cat);
		std::cout << "copyCat's idea[0]: " << copyCat->getBrain()->getIdea(0) << std::endl;
		std::cout << "copyCat's idea[1]: " << copyCat->getBrain()->getIdea(1) << std::endl;
		delete (copyCat);
		std::cout << std::endl;
	}
	{
		std::cout << "---Dog Brain Test---" << std::endl;
		Dog *dog = new Dog();
		dog->getBrain()->setIdea("Amogus");
		std::cout << "dog's idea[0]: " << dog->getBrain()->getIdea(0) << std::endl;
		dog->getBrain()->setIdea("Yummy meat");
		std::cout << "dog's idea[1]: " << dog->getBrain()->getIdea(1) << std::endl;
		Dog	*copyDog = new Dog(*dog);
		delete (dog);
		std::cout << "copyCat's idea[0]: " << copyDog->getBrain()->getIdea(0) << std::endl;
		std::cout << "copyCat's idea[1]: " << copyDog->getBrain()->getIdea(1) << std::endl;
		delete (copyDog);
		std::cout << std::endl;
	}
	// {
	//	//This part should not allow compiling
	// 	AAnimal	*fish = new AAnimal;
	// 	fish->makeSound();
	// 	delete (fish);
	// }
	return (0);
}
