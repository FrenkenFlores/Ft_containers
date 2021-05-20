.PHONY: all clean fclean re test
test:
	cd ./unit_tests && bash test_list.sh
	cd ./unit_tests && bash test_vector.sh



