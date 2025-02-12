#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> m(5));
	//ADD_FAILURE();
}

TEST(TMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
	//ADD_FAILURE();
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-5));
	//ADD_FAILURE();
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> m(5);

	ASSERT_NO_THROW(TMatrix<int> m1(m));
	//ADD_FAILURE();
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(m1);
	EXPECT_EQ(m1, m2);
	//ADD_FAILURE();
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(m1);
	m1[0][0] = 5;
	m2[0][0] = 4;
	ASSERT_NE(m1[0][0], m2[0][0]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m1(5);
	EXPECT_EQ(5, m1.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);
	ASSERT_NO_THROW(m[0][0]=77);
	EXPECT_EQ(77,m[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(5);
	ASSERT_ANY_THROW(m[0][-1] = 77);
	//ASSERT_ANY_THROW(m[-5][4] = 77);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(5);
	//ASSERT_ANY_THROW(m[0][7] = 77);
	ASSERT_ANY_THROW(m[9][2] = 77);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(5);
	m[0][2] = 7; m[1][4] = 5; 
	TMatrix<int> m2(m);
	ASSERT_NO_THROW(m = m); 
	EXPECT_EQ(m2, m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(5);
	m[0][2] = 7; m[1][4] = 5; 
	TMatrix<int> m2(5);
	ASSERT_NO_THROW(m2 = m);
	EXPECT_EQ(m2, m);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m(5);
	TMatrix<int> m2(7);
	ASSERT_NO_THROW(m = m2);
	EXPECT_EQ(7, m.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m(5);
	TMatrix<int> m2(7);
	ASSERT_NO_THROW(m2 = m);
	EXPECT_EQ(m2, m);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m(5),m2(5);
	m2[0][2]=m[0][2] = 7;m2[1][4]= m[1][4] = 5;
	EXPECT_EQ(1, m == m);
	EXPECT_EQ(0, m != m);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(5);
	EXPECT_EQ(1, m == m);
	EXPECT_EQ(0, m != m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m(5);
	TMatrix<int> m2(7);
	EXPECT_NE(m2, m);
	EXPECT_EQ(0, m2 == m);
	EXPECT_EQ(1, m2 != m);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m(5),m2(5),res(5),expRes(5);
	expRes[0][1] = 3; m[0][1] = 1; m2[0][1] = 2;
	expRes[3][3] = 7; m[3][3] = 9; m2[3][3] = -2;
	ASSERT_NO_THROW(res = m+m2);
	EXPECT_EQ(expRes, res);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m(5), m2(7);
	ASSERT_ANY_THROW(m+ m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m(5), m2(5), res(5), expRes(5);
	expRes[0][1] = 3; m[0][1] = 1; m2[0][1] = -2;
	expRes[3][3] = 7; m[3][3] = 9; m2[3][3] = 2;
	ASSERT_NO_THROW(res = m - m2);
	EXPECT_EQ(expRes, res);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m(5), m2(7);
	ASSERT_ANY_THROW(m - m2);
}