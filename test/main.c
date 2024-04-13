/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgerwig- <dgerwig-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:00:03 by dgerwig-          #+#    #+#             */
/*   Updated: 2024/02/02 18:20:10 by dgerwig-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include "../inc/libasm.h"


void print_test_name(char* test_name)
{
	printf("\n*********************************************************");
	printf("\n\033[1mTesting --> \033[0m\033[35m%s\033[0m \n", test_name);
	printf("*********************************************************\n");
}

int main()
{
	bool main_test = true;

	int time_sleep = 1;


	///////////////////////////////////////////////////
	/* ft_strlen */
	///////////////////////////////////////////////////
	{
		print_test_name("ft_strlen");
		
		bool test = true;

		char *test_cases[] = {
			"",						 // empty string
			"very_long_string, and long long string",		 // long string
			"Special char: $€¥😃☻☃︎", // special chars
			"test1\0unreachable",	 // string with null char
			"test2\nreachable",		 // string with newline char
			"test3\r",				 // string with carriage return char
			"test4\t"				 // string with tab char
		};

		for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
		{
			printf("\nTest --> %s\n", test_cases[i]);

			ssize_t result1 = ft_strlen(test_cases[i]);
			int test1_errno_ft = errno;

			ssize_t result2 = strlen(test_cases[i]);
			int test1_errno_std = errno;

			if ((ft_strlen(test_cases[i]) == strlen(test_cases[i])))
			{
				printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m OUTPUT: ft_strlen = %zu // strlen = %zu \033[0m\n", "ft_strlen", "strlen", result1, result2);
				printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m ERRNO:  ft_strlen = %d // strlen = %d \033[0m\n", "ft_strlen", "strlen", test1_errno_ft, test1_errno_std);
			}
			else {
				printf("\033[1;31m  ERROR: \033[0m %s = %s -->\033[33m OUTPUT: ft_strlen = %zu // EXPECTED OUTPUT: strlen = %zu \033[0m\n", "ft_strlen", "strlen", result1, result2);
				test = false;
			}
		}
		
		if(test)
		{
			printf("\n⭐️ All tests in FT_STRLEN passed successfully!\n\n");
			sleep(time_sleep);
		}
		else
		{
			main_test = false;
		}
	}


	///////////////////////////////////////////////////
	/* ft_strcpy */
	///////////////////////////////////////////////////
	{
		print_test_name("ft_strcpy");

		bool test = true;
		
		char* test_cases[] = {
			"",						 // empty string
			"verylongstring",		 // long string
			"Special char: $€¥😃☻☃︎", // special chars
			"test1\0unreachable",	 // string with null char
			"test2\nreachable"		 // string with newline char
		};

		char buf_a[50];
		char buf_b[50];

		for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
		{
			printf("\nTest --> %s\n", test_cases[i]);

			char* result1 = ft_strcpy(buf_a, test_cases[i]);
			int test1_errno_ft = errno;
			
			char* result2 = strcpy(buf_b, test_cases[i]);
			int test1_errno_std = errno;

			if (strcmp(buf_a, buf_b) == 0)
			{
				printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m OUTPUT: ft_strcpy = '%s' // strcpy = '%s' \033[0m\n", "ft_strcpy", "strcpy", result1, result2);
				printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m ERRNO:  ft_strcpy = %d // strcpy = %d \033[0m\n", "ft_strcpy", "strcpy", test1_errno_ft, test1_errno_std);
			}
			else
			{
				printf("\033[1;31m  ERROR: \033[0m %s = %s -->\033[33m OUTPUT: ft_strcpy = '%s' // EXPECTED OUTPUT: strcpy = '%s' \033[0m\n", "ft_strcpy", "strcpy", ft_strcpy(buf_a, test_cases[i]), strcpy(buf_b, test_cases[i]));
				test = false;
			}
		}

		if (test)
		{
			printf("\n⭐️ All tests in FT_STRCPY passed successfully!\n\n");
			sleep(time_sleep);
		}
		else
		{
			main_test = false;
		}
	}


	///////////////////////////////////////////////////
	/* ft_strcmp */
	///////////////////////////////////////////////////
	{
		print_test_name("ft_strcmp");

		bool test = true;

		char* test_cases1[] = {"", ""         , "not empty",  "verylongstring", "Special char: $€¥😃☻☃︎", "test1\0unreachable", "test2\nreachable"};
		char* test_cases2[] = {"", "not empty", ""         ,  "verylongstring", "Special char: $€¥😃☻☃︎", "test1\0unreachable", "test2\nreachable"};
			
		for (size_t i = 0; i < sizeof(test_cases1) / sizeof(test_cases1[0]); i++)
		{
			printf("\nTest --> %s vs %s\n", test_cases1[i], test_cases2[i]);

			int result1 = ft_strcmp(test_cases1[i], test_cases2[i]);
			int test1_errno_ft = errno;
			
			int result2 = strcmp(test_cases1[i], test_cases2[i]);
			int test1_errno_std = errno;

			if (result1 == result2)
			{
				printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m OUTPUT: ft_strcmp = '%d' // strcmp = '%d' \033[0m\n", "ft_strcmp", "strcmp", result1, result2);
				printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m ERRNO:  ft_strcmp = %d // strcmp = %d \033[0m\n", "ft_strcmp", "strcmpp", test1_errno_ft, test1_errno_std);
			}
			else
			{
				printf("\033[1;31m  ERROR: \033[0m %s = %s -->\033[33m OUTPUT: ft_strcmp = '%d' // EXPECTED OUTPUT: strcmp = '%d' \033[0m\n", "ft_strcmp", "strcmp", result1, result2);
				test = false;
			}
		}

		if (test)
		{
			printf("\n⭐️ All tests in STRCMP passed successfully!\n\n");
			sleep(time_sleep);
		}
		else
		{
			main_test = false;
		}
	}


	///////////////////////////////////////////////////
	/* ft_write */
	///////////////////////////////////////////////////
	{
		print_test_name("ft_write");

		bool test = true;

		char* alphabet = "abcdefghijklmnopqrstuvwxyz ";
	
	
		int test1_fd = STDOUT_FILENO;
		const void* test1_buf = alphabet;
		size_t test1_size = strlen(alphabet);

		printf("\nTest --> %d, %s, %zu  -> with STDOUT file descriptor\n", test1_fd, test1_buf, test1_size);

		ssize_t test1_result_ft = ft_write(test1_fd, test1_buf, test1_size);
		int test1_errno_ft = errno;

		ssize_t test1_result_std = write(test1_fd, test1_buf, test1_size);
		int test1_errno_std = errno;

		if (test1_result_ft == test1_result_std)
		{
			printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m OUTPUT: ft_write = %zu // write = %zu \033[0m\n", "ft_write", "write", test1_result_ft, test1_result_std);
			printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m ERRNO:  ft_write = %d // write = %d \033[0m\n", "ft_write", "write", test1_errno_ft, test1_errno_std);
		}
		else
		{
			printf("\033[1;31m  ERROR: \033[0m %s = %s -->\033[33m OUTPUT: ft_write = %zu // EXPECTED OUTPUT: write = %zu \033[0m\n", "ft_write", "write", test1_result_ft, test1_result_std);
			test = false;
		}


		int test2_fd = open("_file_write_test2.txt", O_WRONLY | O_CREAT, 0777);
		if (test2_fd == -1)
		{
			printf("Error opening file\n");
			return 1;
		}
		const void* test2_buf = alphabet;
		size_t test2_size = strlen(alphabet);

		printf("\nTest --> %d, %s, %zu  -> open a file WITH WRITE permissions\n", test2_fd, test2_buf, test2_size);

		ssize_t test2_result_ft = ft_write(test2_fd, test2_buf, test2_size);
		if (test2_result_ft == -1)
		{
			printf("Error writing to file\n");
		}
		int test2_errno_ft = errno;

		ssize_t test2_result_std = write(test2_fd, test2_buf, test2_size);
		if (test2_result_std == -1)
		{
			printf("Error writing to file\n");
		}
		int test2_errno_std = errno;

		close(test2_fd);

		if (test2_result_ft == test2_result_std)
		{
			printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m OUTPUT: ft_write = %zu // write = %zu \033[0m\n", "ft_write", "write", test2_result_ft, test2_result_std);
			printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m ERRNO:  ft_write = %d // write = %d \033[0m\n", "ft_write", "write", test2_errno_ft, test2_errno_std);
		}
		else
		{
			printf("\033[1;31m  ERROR: \033[0m %s = %s -->\033[33m OUTPUT: ft_write = %zu // EXPECTED OUTPUT: write = %zu \033[0m\n", "ft_write", "write", test2_result_ft, test2_result_std);
			test = false;
		}


		int test3_fd = open("_file_write_test3.txt", O_RDONLY | O_CREAT, 0777);
		if (test3_fd == -1)
		{
			printf("Error opening file\n");
			return 1;
		}
		const void *test3_buf = alphabet;
		size_t test3_size = strlen(alphabet);

		printf("\nTest --> %d, %s, %zu  -> open a file WITHOUT WRITE permissions\n", test3_fd, test3_buf, test3_size);

		ssize_t test3_result_ft = ft_write(test3_fd, test3_buf, test3_size);
		if (test3_result_ft == -1)
		{
			printf("Error writing to file\n");
		}
		int test3_errno_ft = errno;

		ssize_t test3_result_std = write(test3_fd, test3_buf, test3_size);
		if (test3_result_std == -1)
		{
			printf("Error writing to file\n");
		}
		int test3_errno_std = errno;

		close(test3_fd);

		if (test3_result_ft == test3_result_std)
		{
			printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m OUTPUT: ft_write = %zu // write = %zu \033[0m\n", "ft_write", "write", test3_result_ft, test3_result_std);
			printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m ERRNO:  ft_write = %d // write = %d \033[0m\n", "ft_write", "write", test3_errno_ft, test3_errno_std);
		}
		else
		{
			printf("\033[1;31m  ERROR: \033[0m %s = %s -->\033[33m OUTPUT: ft_write = %zu // EXPECTED OUTPUT: write = %zu \033[0m\n", "ft_write", "write", test3_result_ft, test3_result_std);
			test = false;
		}


		int test4_fd = -1;
		const void *test4_buf = alphabet;
		size_t test4_size = strlen(alphabet);

		printf("\nTest --> %d, %s, %zu  -> with a WRONG file descriptor\n", test4_fd, test4_buf, test4_size);

		ssize_t test4_result_ft = ft_write(test4_fd, test4_buf, test4_size);
		int test4_errno_ft = errno;

		ssize_t test4_result_std = write(test4_fd, test4_buf, test4_size);
		int test4_errno_std = errno;

		if (test4_result_ft == test4_result_std)
		{
			printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m OUTPUT: ft_write = %zu // write = %zu \033[0m\n", "ft_write", "write", test4_result_ft, test4_result_std);
			printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m ERRNO:  ft_write = %d // write = %d \033[0m\n", "ft_write", "write", test4_errno_ft, test4_errno_std);
		}
		else
		{
			printf("\033[1;31m  ERROR: \033[0m %s = %s -->\033[33m OUTPUT: ft_write = %zu // EXPECTED OUTPUT: write = %zu \033[0m\n", "ft_write", "write", test4_result_ft, test4_result_std);
			test = false;
		}


		int test5_fd = STDOUT_FILENO;
		const void* test5_buf = NULL;
		size_t test5_size = 1;

		printf("\nTest --> %d, %s, %zu  -> with a NULL buffer\n", test5_fd, test5_buf, test5_size);

		ssize_t test5_result_ft = ft_write(test5_fd, test5_buf, test5_size);
		int test5_errno_ft = errno;

		ssize_t test5_result_std = write(test5_fd, test5_buf, test5_size);
		int test5_errno_std = errno;

		if (test5_result_ft == test5_result_std)
		{
			printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m OUTPUT: ft_write = %zu // write = %zu \033[0m\n", "ft_write", "write", test5_result_ft, test5_result_std);
			printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m ERRNO:  ft_write = %d // write = %d \033[0m\n", "ft_write", "write", test5_errno_ft, test5_errno_std);
		}
		else
		{
			printf("\033[1;31m  ERROR: \033[0m %s = %s -->\033[33m OUTPUT: ft_write = %zu // EXPECTED OUTPUT: write = %zu \033[0m\n", "ft_write", "write", test5_result_ft, test5_result_std);
			test = false;
		}


		if (test)
		{
			printf("\n⭐️ All tests in WRITE passed successfully!\n\n");
			sleep(time_sleep);
		}
		else
		{
			main_test = false;
		}
	}
	

	///////////////////////////////////////////////////
	/* ft_read */
	///////////////////////////////////////////////////

	{
		print_test_name("ft_read");

		bool test = true;

		
		char buffer0[1000];
		memset(buffer0, 0, sizeof(buffer0));
		int test0_fd = STDIN_FILENO;
		void* test0_buf = buffer0;
		size_t test0_size = sizeof(buffer0);

		printf("\nTest --> %d, %s, %zu  -> with STDIN file descriptor\n", test0_fd, "🔔 🆘 BUFFER FROM STDIN --> Write something in the prompt 🔔", test0_size);

		ssize_t test0_result_ft = ft_read(test0_fd, test0_buf, test0_size);
		int test0_errno_ft = errno;

		ssize_t test0_result_std = read(test0_fd, test0_buf, test0_size);
		int test0_errno_std = errno;

		if (test0_result_ft == test0_result_std)
		{
			printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m OUTPUT: ft_read = %zu // read = %zu \033[0m\n", "ft_read", "read", test0_result_ft, test0_result_std);
			printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m ERRNO:  ft_read = %d // read = %d \033[0m\n", "ft_read", "read", test0_errno_ft, test0_errno_std);
		}
		else
		{
			printf("\033[1;31m  ERROR: \033[0m %s = %s -->\033[33m OUTPUT: ft_read = %zu // EXPECTED OUTPUT: read = %zu \033[0m\n", "ft_read", "read", test0_result_ft, test0_result_std);
			test = false;
		}


		char buffer1[1000];
		memset(buffer1, 0, sizeof(buffer1));
		int test1_fd = open("_file_read_test1.txt", O_RDONLY);
		if (test1_fd == -1)
		{
			printf("Error opening file\n");
			return 1;
		}
		void* test1_buf = buffer1;
		size_t test1_size = 10;

		printf("\nTest --> %d, %s, %zu  -> open a file WITH READ permissions (not empty file)\n", test1_fd, test1_buf, test1_size);

		ssize_t test1_result_ft = ft_read(test1_fd, test1_buf, test1_size);
		if (test1_result_ft == -1)
		{
			printf("Error writing to file\n");
		}
		int test1_errno_ft = errno;

		ssize_t test1_result_std = read(test1_fd, test1_buf, test1_size);
		if (test1_result_std == -1)
		{
			printf("Error writing to file\n");
		}
		int test1_errno_std = errno;

		close(test1_fd);

		if (test1_result_ft == test1_result_std)
		{
			printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m OUTPUT: ft_read = %zu // read = %zu \033[0m\n", "ft_read", "read", test1_result_ft, test1_result_std);
			printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m ERRNO:  ft_read = %d // read = %d \033[0m\n", "ft_read", "read", test1_errno_ft, test1_errno_std);
		}
		else
		{
			printf("\033[1;31m  ERROR: \033[0m %s = %s -->\033[33m OUTPUT: ft_read = %zu // EXPECTED OUTPUT: read = %zu \033[0m\n", "ft_read", "read", test1_result_ft, test1_result_std);
			test = false;
		}


		char buffer2[1000];
		memset(buffer2, 0, sizeof(buffer2));
		int test2_fd = open("_file_read_test2.txt", O_RDONLY | O_CREAT | O_TRUNC);
		if (test2_fd == -1)
		{
			printf("Error opening file\n");
			return 1;
		}
		void* test2_buf = buffer2;
		size_t test2_size = 10;

		printf("\nTest --> %d, %s, %zu  -> open a file WITH READ permissions (empty file)\n", test2_fd, test2_buf, test2_size);

		ssize_t test2_result_ft = ft_read(test2_fd, test2_buf, test2_size);
		if (test2_result_ft == -1)
		{
			printf("Error writing to file\n");
		}
		int test2_errno_ft = errno;

		ssize_t test2_result_std = read(test2_fd, test2_buf, test2_size);
		if (test2_result_std == -1)
		{
			printf("Error writing to file\n");
		}
		int test2_errno_std = errno;

		close(test2_fd);

		if (test2_result_ft == test2_result_std)
		{
			printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m OUTPUT: ft_read = %zu // read = %zu \033[0m\n", "ft_read", "read", test2_result_ft, test2_result_std);
			printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m ERRNO:  ft_read = %d // read = %d \033[0m\n", "ft_read", "read", test2_errno_ft, test2_errno_std);
		}
		else
		{
			printf("\033[1;31m  ERROR: \033[0m %s = %s -->\033[33m OUTPUT: ft_read = %zu // EXPECTED OUTPUT: read = %zu \033[0m\n", "ft_read", "read", test2_result_ft, test2_result_std);
			test = false;
		}


		char buffer3[1000];
		memset(buffer3, 0, sizeof(buffer3));
		int test3_fd = open("_file_read_test3.txt", O_WRONLY | O_CREAT | O_TRUNC);
		if (test3_fd == -1)
		{
			printf("Error opening file\n");
			return 1;
		}
		void* test3_buf = buffer3;
		size_t test3_size = 10;

		printf("\nTest --> %d, %s, %zu  -> open a file WITHOUT READ permissions\n", test3_fd, test3_buf, test3_size);

		ssize_t test3_result_ft = ft_read(test3_fd, test3_buf, test3_size);
		if (test3_result_ft == -1)
		{
			printf("Error reading from file\n");
		}
		int test3_errno_ft = errno;

		ssize_t test3_result_std = read(test3_fd, test3_buf, test3_size);
		if (test3_result_std == -1)
		{
			printf("Error reading from file\n");
		}
		int test3_errno_std = errno;

		close(test3_fd);

		if (test3_result_ft == test3_result_std)
		{
			printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m OUTPUT: ft_read = %zu // read = %zu \033[0m\n", "ft_read", "read", test3_result_ft, test3_result_std);
			printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m ERRNO:  ft_read = %d // read = %d \033[0m\n", "ft_read", "read", test3_errno_ft, test3_errno_std);
		}
		else
		{
			printf("\033[1;31m  ERROR: \033[0m %s = %s -->\033[33m OUTPUT: ft_read = %zu // EXPECTED OUTPUT: read = %zu \033[0m\n", "ft_read", "read", test3_result_ft, test3_result_std);
			test = false;
		}


		char buffer4[1000];
		memset(buffer4, 0, sizeof(buffer4));
		int test4_fd = -1;
		void* test4_buf = buffer4;
		size_t test4_size = 10;

		printf("\nTest --> %d, %s, %zu  -> with a WRONG file descriptor\n", test4_fd, test4_buf, test4_size);

		ssize_t test4_result_ft = ft_read(test4_fd, test4_buf, test4_size);
		int test4_errno_ft = errno;

		ssize_t test4_result_std = read(test4_fd, test4_buf, test4_size);
		int test4_errno_std = errno;

		if (test4_result_ft == test4_result_std)
		{
			printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m OUTPUT: ft_read = %zu // read = %zu \033[0m\n", "ft_read", "read", test4_result_ft, test4_result_std);
			printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m ERRNO:  ft_read = %d // read = %d \033[0m\n", "ft_read", "read", test4_errno_ft, test4_errno_std);
		}
		else
		{
			printf("\033[1;31m  ERROR: \033[0m %s = %s -->\033[33m OUTPUT: ft_read = %zu // EXPECTED OUTPUT: read = %zu \033[0m\n", "ft_read", "read", test4_result_ft, test4_result_std);
			test = false;
		}


		char buffer5[1000];
		memset(buffer5, 0, sizeof(buffer5));
		int test5_fd = STDIN_FILENO;
		void *test5_buf = NULL;
		size_t test5_size = sizeof(buffer5);

		int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
		fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);

		printf("\nTest --> %d, %s, %zu  -> with a NULL buffer\n", test5_fd, test5_buf, test5_size);

		ssize_t test5_result_ft = ft_read(test5_fd, test5_buf, test5_size);
		int test5_errno_ft = errno;

		ssize_t test5_result_std = read(test5_fd, test5_buf, test5_size);
		int test5_errno_std = errno;

		fcntl(STDIN_FILENO, F_SETFL, flags);
		
		if (test5_result_ft == test5_result_std)
		{
			printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m OUTPUT: ft_read = %zu // read = %zu \033[0m\n", "ft_read", "read", test5_result_ft, test5_result_std);
			printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m ERRNO:  ft_read = %d // read = %d \033[0m\n", "ft_read", "read", test5_errno_ft, test5_errno_std);
		}
		else
		{
			printf("\033[1;31m  ERROR: \033[0m %s = %s -->\033[33m OUTPUT: ft_read = %zu // EXPECTED OUTPUT: read = %zu \033[0m\n", "ft_read", "read", test5_result_ft, test5_result_std);
			test = false;
		}


		char buffer6[1000];
		memset(buffer6, 0, sizeof(buffer6));
		int test6_fd = STDIN_FILENO;
		void *test6_buf = buffer6;
		size_t test6_size = -1;

		printf("\nTest --> %d, %s, %zu  -> with NEGATIVE VALUE in size of reading\n", test6_fd, test6_buf, test6_size);

		ssize_t test6_result_ft = ft_read(test6_fd, test6_buf, test6_size);
		int test6_errno_ft = errno;

		ssize_t test6_result_std = read(test6_fd, test6_buf, test6_size);
		int test6_errno_std = errno;

		if (test6_result_ft == test6_result_std)
		{
			printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m OUTPUT: ft_read = %zu // read = %zu \033[0m\n", "ft_read", "read", test6_result_ft, test6_result_std);
			printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m ERRNO:  ft_read = %d // read = %d \033[0m\n", "ft_read", "read", test6_errno_ft, test6_errno_std);
		}
		else
		{
			printf("\033[1;31m  ERROR: \033[0m %s = %s -->\033[33m OUTPUT: ft_read = %zu // EXPECTED OUTPUT: read = %zu \033[0m\n", "ft_read", "read", test6_result_ft, test6_result_std);
			test = false;
		}


		if (test)
		{
			printf("\n⭐️ All tests in READ passed successfully!\n\n");
			sleep(time_sleep);
		}
		else
		{
			main_test = false;
		}
	}
	
	
	///////////////////////////////////////////////////
	/* strdup */
	///////////////////////////////////////////////////

	{	
		print_test_name("ft_strdup");

		bool test = true;

		char *test_cases[] = {
			"",						 // empty string
			"verylongstring",		 // long string
			"Special char: $€¥😃☻☃︎", // special chars
			"test1\0unreachable",	 // string with null char
			"test2\nreachable"		 // string with newline char
		};

		char* result1;
		char* result2;

		for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++)
		{
			printf("\nTest --> %s\n", test_cases[i]);

			result1 = ft_strdup(test_cases[i]);
			int test1_errno_ft = errno;

			result2 = strdup(test_cases[i]);
			int test1_errno_std = errno;

			if (strcmp(result1, result2) == 0)
			{
				printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m OUTPUT: ft_strdup = '%s' // strdup = '%s' \033[0m\n", "ft_strdup", "strdup", result1, result2);
				printf("\033[1;32m  OK: \033[0m %s == %s -->\033[33m ERRNO:  ft_strdup = %d // strdup = %d \033[0m\n", "ft_strdup", "strdup", test1_errno_ft, test1_errno_std);
			}
			else
			{
				printf("\033[1;31m  ERROR: \033[0m %s = %s -->\033[33m OUTPUT: ft_strdup = '%s' // EXPECTED OUTPUT: strdup = '%s' \033[0m\n", "ft_strdup", "strdup", result1, result2);
				test = false;
			}
			free(result1);
			free(result2);
		}


		if (test)
		{
			printf("\n⭐️ All tests in FT_STRDUP passed successfully!\n\n");
			sleep(time_sleep);
		}
		else
		{
			main_test = false;
		}
	}


	printf("\n\n🟠 CHEKING LEAKS with --> \033[33msystem(\"leaks test_libasm\")\033[0m\n");
	system("leaks test_libasm");


	if (main_test)
	{
		printf("\n⭐️⭐️⭐️ \033[1;32m All tests in LIBASM have passed successfully! \033[0m ⭐️⭐️⭐️\n\n");
	}
	else
	{
		printf("\n❌ ❌ ❌ Some tests in LIBASM have failed! ❌ ❌ ❌\n\n");
	}

	return (0);
}
