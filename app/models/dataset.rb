# == Schema Information
#
# Table name: datasets
#
#  id          :integer          not null, primary key
#  path        :string
#  name        :string
#  type        :string
#  description :text
#  team_id     :integer
#  owner_id    :integer
#  created_at  :datetime         not null
#  updated_at  :datetime         not null
#

class Dataset < ActiveRecord::Base
end
