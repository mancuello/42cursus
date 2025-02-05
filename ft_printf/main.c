/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:28:06 by mcuello           #+#    #+#             */
/*   Updated: 2025/02/05 12:54:06 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
    // char    caracter = 'a';
    // char    *string = "hola mundo";
    // int     number = 200;
	
    // //Prueba solo de caracteres.
	// ft_printf("Custom print\n");
	// printf("Original Print\n");

    // //Prueba con especificador %c
    // ft_printf("Custom  => char: %c\n", caracter);
    // printf("Original=> char: %c\n", caracter);

    // //Prueba con especificador %s
    // ft_printf("Custom  => char: %s\n", string);
    // printf("Original=> char: %s\n", string);
    // //Prueba con especificador %p
    // ft_printf("Custom  => char: %p\n", NULL);
    // printf("Original=> char: %p\n", NULL);
	// ft_printf("Custom  => char: %p\n", string);
    // printf("Original=> char: %p\n", string);

    // //Prueba con especificador %d
    // ft_printf("Custom  => char: %d\n", number);
    // printf("Original=> char: %d\n", number);

    // //Prueba con especificador %i
    // ft_printf("Custom  => char: %i\n", number);
    // printf("Original=> char: %i\n", number);

    // //Prueba con especificador %u
    // ft_printf("Custom  => char: %u\n", number);
    // printf("Original=> char: %u\n", number);

    // //Prueba con especificador %x
    // ft_printf("Custom  => char: %x\n", number);
    // printf("Original=> char: %x\n", number);

    // //Prueba con especificador %X
    // ft_printf("Custom  => char: %X\n", number);
    // printf("Original=> char: %X\n", number);

    // //Prueba con especificador %%
    // ft_printf("Custom  => char: %%\n");
    // printf("Original=> char: %%\n");

	// //Prueba con varios especificadores
	// ft_printf("Custom  => char: %c, int: %i, dec: %d, unsigned: %u, hexa: %x, hexaM: %X, pointer: %p\n", 'a', 123, 123, 123, 123, 123, &caracter);
	// printf("Original=> char: %c, int: %i, dec: %d, unsigned: %u, hexa: %x, hexaM: %X, pointer: %p\n", 'a', 123, 123, 123, 123, 123, &caracter);

	// //Prueba de retorno
	// printf("Se imprimieron: %i caracteres con la funcion ft_printf.\n", ft_printf("Se imprimira el numero: %i y \"%s\" string\n", 300, string));
	// ft_printf("Se imprimieron: %i caracteres con la funcion printf.\n", printf("Se imprimira el numero: %i y \"%s\" string\n", 300, string));

	// //Prueba error
	// //printf("Probando especificador \"j\": %j", 38);
	// //ft_printf("Probando especificador \"j\": %j", 38);

    printf("%p \n", (char *)NULL);
    ft_printf("%p \n", NULL);
	return (0);
}