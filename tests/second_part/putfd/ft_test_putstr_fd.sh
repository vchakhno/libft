#!/bin/bash
if [ "$(./ft_test_putstr_fd.out 2>/dev/null)" != "Hello" ]; then
	echo "ft_putstr_fd: failed to output to stdout"
	exit
fi
if [ "$(./ft_test_putstr_fd.out 2>&1 1>/dev/null)" != "Velimir" ]; then
	echo "ft_putstr_fd: failed to output to stderr"
	exit
fi
echo "ft_putstr_fd: OK"
