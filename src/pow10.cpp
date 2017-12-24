static const float _pow10[] = { 1e-6, 1e-5, 1e-4, 1e-3, 1e-2, 1e-1, 1e0, 1e1, 1e2, 1e3, 1e4, 1e5, 1e6 };

float pow10(int y)
{
  // must be: y = -6 .. +6
  if (y < -6 || y > 6)
    return 0;
  return _pow10[y + 6];
}
