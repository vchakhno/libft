#!/bin/bash
if [ "$(./ft_test_putchar_fd.out 2>/dev/null)" != "Bonjour" ]; then
	echo "ft_putchar_fd: failed to output to stdout"
	exit
fi
if [ "$(./ft_test_putchar_fd.out 2>&1 1>/dev/null)" != "Velimir" ]; then
	echo "ft_putchar_fd: failed to output to stderr"
	exit
fi
echo "ft_putchar_fd: OK"
