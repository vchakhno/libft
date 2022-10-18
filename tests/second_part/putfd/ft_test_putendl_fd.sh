#!/bin/bash
if [ "$(./ft_test_putendl_fd.out 2>/dev/null; printf _)" != $'Hello\n_' ]; then
	echo "ft_putendl_fd: failed to output to stdout"
	exit
fi
if [ "$(./ft_test_putendl_fd.out 2>&1 1>/dev/null; printf _)" != $'Velimir\n_' ]; then
	echo "ft_putendl_fd: failed to output to stderr"
	exit
fi
echo "ft_putendl_fd: OK"
