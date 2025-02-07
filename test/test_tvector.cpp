#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(10);
	TVector<int> m(v);
	EXPECT_EQ(v, m);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v(10);
	TVector<int> m(v);
	v[0] = 71;
	EXPECT_EQ(0, v[0]==m[0]);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;
  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(4);
	ASSERT_ANY_THROW(v[-1]= 4);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(4);
	ASSERT_ANY_THROW(v[5] = 4);

}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> v(5), m(5);
	v[4] = m[4] = 5;
	v[2] = m[2] = 7;
	ASSERT_NO_THROW(v=v);
	EXPECT_EQ(v, m);
  //ADD_FAILURE();
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> v(4),m(4);
	v = m;
	EXPECT_EQ(v, m);
	//ADD_FAILURE();
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v(4), m(7);
	v = m;
	EXPECT_EQ(7, v.GetSize());
	//ADD_FAILURE();
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> v(4), m(8);
	m[4] = 5;
	v = m;
	EXPECT_EQ(v, m);
	//ADD_FAILURE();
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v(8), m(8);
	v[4]=m[4] = 5;
	v[2] = m[2] = 7;
	EXPECT_EQ(1,v==m);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v(8);
	v[4]  = 5;
	v[2]  = 7;
	EXPECT_EQ(1, v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v(5), m(8);
	v[4] = m[4] = 5;
	v[2] = m[2] = 7;
	EXPECT_EQ(0, v == m);
	EXPECT_EQ(1, v != m);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> v(5), res(5);
	for (int i = 0; i < res.GetSize(); ++i) res[i] = 9;
	EXPECT_EQ(res, v + 9);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> v(5), res(5);
	for (int i = 0; i < res.GetSize(); ++i) { v[i] = 11; res[i] = 9; }
	EXPECT_EQ(res, v - 2);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v(5), res(5);
	for (int i = 0; i < res.GetSize(); ++i) { v[i] = 11; res[i] = 33; }
	EXPECT_EQ(res, v *3);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v(5),v2(5), res(5),expRes(5);
	v[0] = 7; v[3] = 5; v[1] = 9; v2[1] = 2;
	expRes[0] = 7; expRes[3] = 5; expRes[1] = 11;
	ASSERT_NO_THROW(res = v+v2);
	EXPECT_EQ(expRes, res);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v(5), v2(7);
	ASSERT_ANY_THROW(v + v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v(5), v2(5), res(5), expRes(5);
	v[0] = 7; v[3] = 5; v[1] = 9; v2[1] = 2;
	expRes[0] = 7; expRes[3] = 5; expRes[1] = 7;
	ASSERT_NO_THROW(res = v - v2);
	EXPECT_EQ(expRes, res);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v(5), v2(7);
	ASSERT_ANY_THROW(v - v2);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	int res;
	TVector<int> v(5), v2(5);
	v[0] = 5; v2[0] = 3;
	v[3] = 4; v2[3] = 2;
	ASSERT_NO_THROW(res = v * v2);
	EXPECT_EQ(23, res);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v(5), v2(7);
	ASSERT_ANY_THROW(v * v2);
}

TEST(TVector, operator_ne) {
    const int n = 10, si = 3;
    TVector<int> v1(n, si), v2(n, si);
    v1[4] = 1;
    v2[4] = 2;
    ASSERT_TRUE(v1 != v2);
}

TEST(TVector, operator_eq) {
    const int n = 10, si = 3;
    TVector<int> v1(n, si), v2(n, si);
    v1[4] = 1;
    v2[4] = 2;
    ASSERT_FALSE(v1 == v2);
}
