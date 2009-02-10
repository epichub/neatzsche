//#include <unistd.h>
#if defined(WIN32)
#include <windows.h>
#endif

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <GL/gl.h>
#include <GL/glut.h>
#include <time.h>

#include <X11/Xlib.h>
#include <GL/glx.h>

using namespace std;

typedef enum {m_sleep, m_work, m_destroy, m_display} wmode_t;

int worktime = 30 * 60;
int sleeptime = 3 * 60;
time_t sleep_start_time;

int cur_win;
bool first = true;

wmode_t cur_mode;

void w_alarm(int mode); // Forward declaration

void bogus_display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 0.0, 1.0);
  glPolygonMode(GL_FRONT, GL_LINE);
  glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, 0.5);
  glEnd();
//  glRectf(-0.5, -0.5, 0.5, 0.5);
  glFlush();
  //  glutSwapBuffers();
}

void draw_progress_bar(float xpos) // -1 <= xpos <= 1
{
  glPolygonMode(GL_FRONT, GL_FILL);
  glBegin(GL_POLYGON);
    glVertex2f(-1, -1);
    glVertex2f(xpos, -1);
    glVertex2f(xpos, -0.98);
    glVertex2f(-1, -0.98);
  glEnd();
}

void display_work()
{
  //  glClearColor(0.1, 0.0, 0.3, 0.0);

  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 0.0, 0.0);
  draw_progress_bar(2*static_cast<double>(time(0) - sleep_start_time)/sleeptime -1);

  glColor3f(0.0, 1.0, 0.0);
  glPolygonMode(GL_FRONT, GL_LINE);
  glBegin(GL_POLYGON);
  glVertex2f(-0.5, -0.5);
  glVertex2f(0.5, -0.5);
  glVertex2f(0.5, 0.5);
  glVertex2f(-0.5, 0.5);
  glEnd();
  //  glRectf(-0.5, -0.5, 0.5, 0.5);
  glFlush();
  //    glutSwapBuffers();
}


void update_sleep_display(int nada)
{
  if (sleep_start_time + sleeptime < time(0) )
    w_alarm(m_work);
  else
    glutPostRedisplay();
}

void display_sleep()
{
//  glClearColor(0.3, 0.0, 0.1, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
/*  glColor3f(1.0, 0.0, 0.0);
  glPolygonMode(GL_FRONT, GL_LINE);
  glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, 0.5);
  glEnd();
*/
  glColor3f(0.1, 0.4, 0.5);
  draw_progress_bar(2*static_cast<double>(time(0) - sleep_start_time)/sleeptime -1);
  glFlush();
//    glutSwapBuffers();
  glutTimerFunc(1000, update_sleep_display, 0);
}


void keyboard(unsigned char key, int x, int y)
{
  glutDestroyWindow(cur_win);
  glutTimerFunc(worktime*1000, w_alarm, m_sleep);
}


void w_alarm(int mode)
{
  if (mode == m_sleep){
    cur_win = glutCreateWindow("Breaker");
    glutDisplayFunc(display_sleep);
    glutKeyboardFunc(0);
    glutFullScreen();
    //glutTimerFunc(sleeptime*1000, w_alarm, m_work);
    time(&sleep_start_time);
  } else {
    glutDisplayFunc(display_work);
    glutKeyboardFunc(keyboard);
    glutPostRedisplay();
  }
}


int main(int argc, char **argv)
{
  if (argc == 3 && atoi(argv[1]) && atoi(argv[2])){
    worktime = static_cast<unsigned long>(atol(argv[1]));
    sleeptime = static_cast<unsigned long>(atol(argv[2]));
  }

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);

  string displayName = getenv( "DISPLAY");
  Display *pDisp = XOpenDisplay( displayName.c_str() );
  if (!pDisp)
  {
    cerr << "Unable to open display.\n";
    return 1;
  }
  if (glXQueryExtension(pDisp, 0, 0))
    cerr << "OpenGL GLX extension supported by display ";
  else
    cerr << "OpenGL GLX extension NOT supported by display ";
  cerr << XDisplayName( displayName.c_str() ) << "\n";

  char orig_title[256];
  sprintf(orig_title, "Hit a key to start.  Worktime is %i seconds (%.2f min), sleeptime %i (%.2f min).",
          worktime, worktime/60.0, sleeptime, sleeptime/60.0);
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(175, 400);
  cur_win = glutCreateWindow(orig_title);
  glutDisplayFunc(bogus_display);
  glutKeyboardFunc(keyboard);

  std::cerr << "Current settings are:\tWork: " << worktime << " seconds.\tSleep: " << sleeptime << " seconds.\n";
  glutMainLoop();
  return 0;
}


