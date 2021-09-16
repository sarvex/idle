
/*
 *   _____    _ _        .      .    .
 *  |_   _|  | | |  .       .           .
 *    | |  __| | | ___         .    .        .
 *    | | / _` | |/ _ \                .
 *   _| || (_| | |  __/ github.com/Naios/idle
 *  |_____\__,_|_|\___| AGPL v3 (Early Access)
 *
 * Copyright(c) 2018 - 2021 Denis Blank <denis.blank at outlook dot com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <idle/idle.hpp>

using namespace idle;

class HelloService final : public Implements<Autostarted> {
public:
  explicit HelloService(Inheritance inh)
    : Implements<Autostarted>(std::move(inh)) {}

  continuable<> onStart() override {
    return async([this] {
      IDLE_LOG_INFO(log_,
                    "Welcome to Idle!\n"
                    "This is a simple service prototype :)\n"
                    "Change its behaviour by editing its source file at '{}'.",
                    IDLE_CURRENT_SOURCE_LOCATION().file_path());
    });
  }

private:
  Dependency<Log> log_{*this};
};

IDLE_DECLARE(HelloService)