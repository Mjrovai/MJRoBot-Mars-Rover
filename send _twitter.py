from twython import Twython

C_KEY = "w9QZlZghRG0EUrmngsO7N9DP8"
C_SECRET = "Zhq07sMoGtIIsTixHRprU1goJadakR30CovAOR16pMg6CwIQLW"
A_TOKEN = "1958671394-lXtxxWFqJuBzGmTnBZDbRrprEbEJIboOsFGfwOJ"
A_SECRET = "P7zqXu6ME2ODwnhF2vPWqgia5aFNuMVXrHbelPeL2BhoJ"

api = Twython(C_KEY, C_SECRET, A_TOKEN, A_SECRET)
api.update_status(status="IoT Capstone Project - Tweet test")


