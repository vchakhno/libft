#!/bin/bash
if [ "$(./ft_test_putnbr_fd.out 2>/dev/null)" != "0422147483647-2147483648" ]; then
	echo "ft_putnbr_fd: failed to output to stdout"
	exit
fi
if [ "$(./ft_test_putnbr_fd.out 2>&1 1>/dev/null)" != "0-542147483647-2147483648" ]; then
	echo "ft_putnbr_fd: failed to output to stderr"
	exit
fi
echo "ft_putnbr_fd: OK"
