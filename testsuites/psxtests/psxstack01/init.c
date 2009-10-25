/*
 *  COPYRIGHT (c) 1989-2009.
 *  On-Line Applications Research Corporation (OAR).
 *
 *  The license and distribution terms for this file may be
 *  found in the file LICENSE in this distribution or at
 *  http://www.rtems.com/license/LICENSE.
 *
 *  $Id$
 */

#define __RTEMS_VIOLATE_KERNEL_VISIBILITY__
#include <pmacros.h>
#include <errno.h>
#include <pthread.h>
#include <sched.h>

#include <rtems/posix/pthread.h> /* for PTHREAD_MINIMUM_STACK_SIZE */

void *Stack_Low;
void *Stack_High;

void *Test_Thread(void *arg)
{
  #if defined(__GNUC__)
    void *sp = __builtin_frame_address(0);

    #if 0
      printf( "Stack(%p - %p) and sp=%p\n", Stack_Low, Stack_High, sp );
    #endif

    if ( sp >= Stack_Low && sp <= Stack_High )
      puts( "Test_Thread - running on user provided stack - OK" );
    else {
      puts( "Test_Thread - ERROR running on other stack" );
      rtems_test_exit(0);
    }
  #else
      puts( "Test_Thread - no way to get stack pointer and verify" );
  #endif
  puts( "Test_Thread - delete self" );
  return NULL;
}

void *POSIX_Init(
  void *argument
)
{
  int                 sc;
  pthread_t           id;
  pthread_attr_t      attr;

  puts( "\n\n*** POSIX STACK ATTRIBUTE TEST 01 ***" );

  puts( "Init - Allocate stack from heap" );
  Stack_Low = malloc(PTHREAD_MINIMUM_STACK_SIZE);
  assert( Stack_Low );
  Stack_High = Stack_Low + PTHREAD_MINIMUM_STACK_SIZE;

  puts( "Init - Initialize thread attribute for user provided stack" ); 
  sc = pthread_attr_init( &attr );
  assert( !sc );

  sc = pthread_attr_setstackaddr( &attr, Stack_Low );
  assert( !sc );

  sc = pthread_attr_setstacksize( &attr, PTHREAD_MINIMUM_STACK_SIZE );
  assert( !sc );

  /* create threads */
  sc = pthread_create( &id, &attr, Test_Thread, NULL );
  assert( !sc );

  puts( "Init - let other thread run" );
  usleep( 500000 );

  puts( "*** END OF POSIX STACK ATTRIBUTE TEST 01 ***" );
  rtems_test_exit(0);

  return NULL; /* just so the compiler thinks we returned something */
}

/* configuration information */

#define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER
#define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER

#define CONFIGURE_MAXIMUM_POSIX_THREADS        2

#define CONFIGURE_POSIX_INIT_THREAD_TABLE

#define CONFIGURE_INIT
#include <rtems/confdefs.h>
