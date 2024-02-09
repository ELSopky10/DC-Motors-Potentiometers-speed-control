int s_r=4;
int s_l=2;
int m_r=10;
int m_l=11;
int p_r=A5;
int p_l=A1;
void setup()
{
  pinMode(s_r,0);
  pinMode(s_l,0);
  
  pinMode(m_r,1);
  pinMode(m_l,1);
   Serial.begin(9600);
}

void loop()
{
  int o_r=digitalRead(s_r);
  int o_l=digitalRead(s_l);
  int readingpot_r=map analogRead(p_r);
  int readingpot_l=map analogRead(p_l);
                       
  if (o_r==1&&o_l==0)
  {
    analogWrite(m_r,readingpot_r);
    analogWrite(m_l,0);
  }
  else if (o_l==1&&o_r==0)
  {
    analogWrite(m_l,readingpot_l);
    analogWrite(m_r,0);  
  }
  else if (o_==1&&o_l==1)
  {
   analogWrite(m_r,readingpot_r);  
   analogWrite(m_l,readingpot_l);
  }
  else if (o_r==0&&o_l==0)
  {
    analogWrite(m_l,0);
    analogWrite(m_r,0); 
  }
  if (Serial.available())
  {
    char reading=Serial.read();
    if (reading=='R')
    {
      analogWrite(m_r,readingpot_r);
    }
    else if (reading=='L')
    {
      analogWrite(m_l,readingpot_l);
    }
    else if (reading =='S')
    {
      analogWrite(m_l,0);
      analogWrite(m_r,0); 
    }
  }       
}