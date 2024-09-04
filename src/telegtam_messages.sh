BOT_TOKEN="Bot token"
TELEGRAM_USER_ID="user id"

URL="https://api.telegram.org/bot$BOT_TOKEN/sendMessage"
TEXT="$1 $CI_PROJECT_NAME%0AJOB_STAGE%0ASTATUS:$CI_JOB_STATUS"

curl -s -d "chat_id=$TELEGRAM_USER_ID&disable_web_page_preview=1&text=$TEXT" $URL > dev/null


if [ "$CI_JOB_STATUS" == "success" ]; then
text ="$if [ "$CI_JOB_STATUS" == "success" ]; then
MESSAGE="$CI_JOB_STAGE ✅"
else
MESSAGE="$CI_JOB_STAGE 🚫"
fi
fi"

curl -s -X POST https://api.telegram.org/bot${BOT_TOKEN}/sendMessage -d chat_id=${CHAT_WITH_USER_ID} -d text="${MESSAGE}" -d parse_mode="html"

