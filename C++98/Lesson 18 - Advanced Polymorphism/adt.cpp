class Shape
{

 public:
      Shape(){}
      virtual ~Shape(){}
      virtual long GetArea() = 0; 
      virtual long GetPerim()= 0;
      virtual void Draw() = 0;
 private:
};

