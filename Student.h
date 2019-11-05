
class Student
{
public:
  Student();
  Student(int w, int t);
  ~Student();

  int wait;
  int windowTime;
};

bool operator<(const Student &s1, const Student &s2);
