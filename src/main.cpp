#include <dpp/dpp.h>
#include <fmt/core.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <cctype>

constexpr bool clear_commands = false;

void handle_macros(const dpp::message_create_t& event, const std::string& msg) {
  if(msg.find("joever") != std::string::npos) {
    dpp::message m(event.msg.channel_id, "");
    m.add_file("joever.png", dpp::utility::read_file("joever.png"));
    event.reply(m);
  }
  if(msg.find("barack") != std::string::npos) {
    dpp::message m(event.msg.channel_id, "");
    m.add_file("we're barack.png", dpp::utility::read_file("we're barack.png"));
    event.reply(m);
  }
  if(msg == "shaq" || msg.find("i owe you an apology") != std::string::npos || msg.find("i wasn't really familiar with your game") != std::string::npos) {
    dpp::message m(event.msg.channel_id, "");
    m.add_file("shaq apology.png", dpp::utility::read_file("shaq apology.png"));
    event.reply(m);
  }
  if(msg == "daddiuwu") {
    dpp::message m(event.msg.channel_id, "");
    m.add_file("daddiuwu.png", dpp::utility::read_file("daddiuwu.png"));
    event.reply(m);
  }
  if(msg == "lie detected") {
    dpp::message m(event.msg.channel_id, "");
    m.add_file("lie detected.gif", dpp::utility::read_file("lie detected.gif"));
    event.reply(m);
  }
  if(msg == "boush" || (msg.find("dunked") != std::string::npos)) {
    dpp::message m(event.msg.channel_id, "");
    m.add_file("BOUSH.gif", dpp::utility::read_file("BOUSH.gif"));
    event.reply(m);
  }
  if(msg == "che cazzo dici") {
    dpp::message m(event.msg.channel_id, "");
    m.add_file("che cazzo dici.gif", dpp::utility::read_file("che cazzo dici.gif"));
    event.reply(m);
  }
  if(msg == "sujano: this is not true") {
    dpp::message m(event.msg.channel_id, "");
    m.add_file("this is not true sujano.gif", dpp::utility::read_file("this is not true sujano.gif"));
    event.reply(m);
  }
  if(msg.find("that's too easy") != std::string::npos) {
    dpp::message m(event.msg.channel_id, "");
    m.add_file("TOO EASY MAN.gif", dpp::utility::read_file("TOO EASY MAN.gif"));
    event.reply(m);
  }
  if(msg.find("shit's hard") != std::string::npos || msg.find("this shit hard") != std::string::npos || msg.find("this shit is hard") != std::string::npos) {
    dpp::message m(event.msg.channel_id, "");
    m.add_file("THIS SHIT HARD.gif", dpp::utility::read_file("THIS SHIT HARD.gif"));
    event.reply(m);
  }
}

int main() {
  std::string token;
  std::ifstream token_file("token.txt");
  if (token_file.is_open()) {
    std::getline(token_file, token);
    token_file.close();
  } else {
    fmt::print("Failed to open token file\n");
    return 1;
  }

  dpp::cluster bot(token, dpp::i_default_intents | dpp::i_message_content);

  bot.on_message_create([](const dpp::message_create_t& event) {
    if (event.msg.author.is_bot()) {
      return;
    }

    std::string lowercase_msg = event.msg.content;
    std::ranges::transform(
        lowercase_msg, lowercase_msg.begin(),
      [](const unsigned char c) { return std::tolower(c); });

    handle_macros(event, lowercase_msg);
  });

  bot.start(dpp::st_wait);
  return 0;
}