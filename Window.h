
class Window
{
public:
  Window();
  Window(int t, int iT);
  ~Window();

  int windowTime;
  int idleTime;
};

bool operator<(const Window &w1, const Window &w2);
