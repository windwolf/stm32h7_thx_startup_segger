#include "unit_test.h"
#include "communication_protocol/inc/message_parser_test.h"
#include "communication_protocol/inc/nmea_test.h"
#include "communication_protocol/inc/tree_accessor_test.h"
#include "algorithm/inc/kf_test.h"
#include "algorithm/inc/pid_test.h"
#include "stdint.h"
#include "stdio.h"
#define LOG_MODULE test
#include "log.h"
#include "arm_math.h"

#ifdef UNITTEST

void test_before_hal_init()
{

	kf_test();
	message_parser_test();
	tree_accessor_test();
}

void test_after_hal_init()
{
}

#endif //UNITTEST