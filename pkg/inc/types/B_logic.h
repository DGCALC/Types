//
// Created by Lucius Schoenbaum on 3/28/22.
//

// todo: add to Bytearray anything you might wish to do with a Boolean;
// todo flesh out the Bytearray type.

/*
 *
 * GOAL:
 * ..., B<n>, ..., B64, B32, B16, Bbyte, Bool
 *
 */

#pragma once

#include <kyte/bytearray.h>

using B64 = Kyte::Bytearray<8>;
using B32 = Kyte::Bytearray<4>;
using B16 = Kyte::Bytearray<2>;
using Bbyte = Kyte::Bytearray<1>;

// The Bool type, like all the "B" types above,
// can be used for boolean (2-valued) logic.
// todo: research sizeof(bool)
// todo: can do Bool x; x = 1; x = -1; x = 0; if(x) if (!x)  <-- implicit cast to bool, operator!, etc.
using Bool = Kyte::Bytearray<sizeof(bool)>;

