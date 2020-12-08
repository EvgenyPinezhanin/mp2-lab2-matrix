#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m(5);

	for (int i = 0; i < m.GetSize(); i++)
	{
		for (int j = i; j < m.GetSize(); j++)
		{
			m[i][j] = i + j;
		}
	}

	TMatrix<int> m1(m);

	EXPECT_EQ(m, m1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m(5);
	TMatrix<int> m1(m);
	EXPECT_NE(&(m[0][0]), &(m1[0][0]));
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(5);
	EXPECT_EQ(5, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);
	m[0][0] = 9;
	EXPECT_EQ(9, m[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(5);

	ASSERT_ANY_THROW(m[-1][-1] = 5);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(5);

	ASSERT_ANY_THROW(m[5][5] = 5);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(5);
	ASSERT_NO_THROW(m = m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m(5), m1(5);

	for (int i = 0; i < m.GetSize(); i++)
	{
		for (int j = i; j < m.GetSize(); j++)
		{
			m[i][j] = i + j;
		}
	}
	
	m1 = m;
	EXPECT_EQ(m, m1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m(7), m1(5);
	m = m1;
	EXPECT_EQ(5, m.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> m(7), m1(5);

	for (int i = 0; i < m.GetSize(); i++)
	{
		for (int j = i; j < m.GetSize(); j++)
		{
			m[i][j] = i + j;
		}
	}

	m1 = m;
	EXPECT_EQ(m, m1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m(5), m1(5);
	for (int i = 0; i < m.GetSize(); i++)
	{
		for (int j = i; j < m.GetSize(); j++)
		{
			m[i][j] = i + j;
			m1[i][j] = i + j;
		}
	}

	EXPECT_EQ(true, m == m1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m(5);
	for (int i = 0; i < m.GetSize(); i++)
	{
		for (int j = i; j < m.GetSize(); j++)
		{
			m[i][j] = i + j;
		}
	}

	EXPECT_EQ(true, m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m(5), m1(7);
	EXPECT_NE(false, m != m1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m(5), m1(5), m2(5);
	for (int i = 0; i < m.GetSize(); i++)
	{
		for (int j = i; j < m.GetSize(); j++)
		{
			m[i][j] = i;
			m1[i][j] = m.GetSize() - i;
			m2[i][j] = m.GetSize();
		}
	}
	EXPECT_EQ(m2, m + m1);
}

TEST(TMatrix, can_add_matrices_with_equal_size_2)
{
	TMatrix<int> m(3), m1(3), m2(3);
	m[0][0] = 5; m[0][1] = 4; m[0][2] = 2;
	m[1][1] = 15; m[1][2] = 45;
	m[2][2] = 51;

	m1[0][0] = 52; m1[0][1] = 19; m1[0][2] = 1;
	m1[1][1] = 0; m1[1][2] = 4;
	m1[2][2] = 2;

	m2[0][0] = 57; m2[0][1] = 23; m2[0][2] = 3;
	m2[1][1] = 15; m2[1][2] = 49;
	m2[2][2] = 53;
	EXPECT_EQ(m2, m + m1);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m(5), m1(7);
	ASSERT_ANY_THROW(m + m1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m(5), m1(5), m2(5);
	for (int i = 0; i < m.GetSize(); i++)
	{
		for (int j = i; j < m.GetSize(); j++)
		{
			m[i][j] = i;
			m1[i][j] = i;
		}
	}
	EXPECT_EQ(m2, m - m1);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m(5), m1(7);
	ASSERT_ANY_THROW(m - m1);
}

