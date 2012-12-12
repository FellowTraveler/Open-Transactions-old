# Before running this script, make sure the _otapi.so and
# the otapi.py are both in a folder on the path:  $PYTHONPATH
#
# Also, make sure the server is running ('otserver')

import otapi
otapi.OTAPI_Basic_AppStartup()

otapi.OTAPI_Basic_Init()
otapi.OTAPI_Basic_LoadWallet()

count = otapi.OTAPI_Basic_GetServerCount()
print count

objEasy = otapi.OTMadeEasy()
strCheck = objEasy.check_user('tBy5mL14qSQXCJK7Uz3WlTOKRP9M0JZksA3Eg7EnnQ1', 'T1Q3wZWgeTUoaUvn9m1lzIK5tn5wITlzxzrGNI8qtaV', 'T1Q3wZWgeTUoaUvn9m1lzIK5tn5wITlzxzrGNI8qtaV')

nResult = objEasy.VerifyMessageSuccess(strCheck)
print nResult

otapi.OTAPI_Basic_AppShutdown()

