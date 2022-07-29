#include "mycamera.h"

myCamera::~myCamera()
{

}

void myCamera::openVideoCamera(){
    if(!m_cap.isOpened()){
        m_cap.open(0);

        timer_myCamera.start(20,this);
        emit started();
    }
}

void myCamera::timerEvent(QTimerEvent *ev){
    if(ev->timerId() != timer_myCamera.timerId()){
        return;
    }
    if(!m_cap.read(frame_myCamera)){
        timer_myCamera.stop();
        return;
    }
    emit matReady(frame_myCamera);
}

void myCamera::stopped(){
    timer_myCamera.stop();
}





/*Note
 *
 *QTimeEvent
 *Timer events are sent at regular intervals to objects that have started one or more timers.
 *Each timer has a unique identifier.
 *
 *
 */
